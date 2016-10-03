uint8_t sPciNo[] = {
  18, 20, 22, 23, 0, 1, 2, 3, 4, 5, // D0-9
  8, 9, 10, 11, 12, 13 // A0-5
};

void setInterrupt(uint8_t pin) {
  if (pin >= sizeof(sPciNo)) {
    return;
  }
  uint8_t pciNo = sPciNo[pin];
  uint8_t group = pciNo / 8;
  PCICR |= _BV(group);
  *(&PCMSK0 + group) |= _BV(pciNo % 8);
}

boolean a3 = false;
boolean a3Changed = false;

void setup() {
  pinMode(A3, INPUT);
  setInterrupt(A3);
  a3 = digitalRead(A3);
  setLed(a3);
}

void loop() {
    Bean.sleep(0xFFFFFFFF);
    setLed(a3);
}

void setLed(boolean b) {
  if (b) {
    Bean.setLed(0,30,0);
  } else {
    Bean.setLed(0,0,0);
  }
}

ISR(PCINT0_vect) {
}

ISR(PCINT1_vect) {
  bool old = a3;
  a3 = digitalRead(A3);
  a3Changed = a3 != old;
}


ISR(PCINT2_vect) {
}