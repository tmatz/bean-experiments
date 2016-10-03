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

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);

  setInterrupt(A5);
}

void loop() {
    Bean.setLed(0,0,0);
    Bean.sleep(0xFFFFFFFF);
    Bean.setLed(0,0,30);    
    Bean.sleep(100);
}

ISR(PCINT0_vect) {
}

ISR(PCINT1_vect) {
}

ISR(PCINT2_vect) {
}