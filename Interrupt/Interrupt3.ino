#define BEAN_PCINT_D0 18
#define BEAN_PCINT_D1 20
#define BEAN_PCINT_D2 22
#define BEAN_PCINT_D3 23
#define BEAN_PCINT_D4 0
#define BEAN_PCINT_D5 1
#define BEAN_PCINT_D6 2
#define BEAN_PCINT_D7 3
#define BEAN_PCINT_D8 4
#define BEAN_PCINT_D9 5
#define BEAN_PCINT_A0 8
#define BEAN_PCINT_A1 9
#define BEAN_PCINT_A2 10
#define BEAN_PCINT_A3 11
#define BEAN_PCINT_A4 12
#define BEAN_PCINT_A5 13

#define PIN_INT 18

void setInterrupt(uint8_t pciNo) {
  int group = pciNo / 8;
  PCICR |= _BV(group);
  *(&PCMSK0 + group)|= _BV(pciNo % 8);
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

  setInterrupt(PIN_INT);
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