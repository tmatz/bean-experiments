boolean interruptSeen = false;

#define BEAN_PCINT_D0 PCINT22
#define BEAN_PCINT_D1 PCINT1

void setup() {
    // which happens to be PCINT22
    PCICR |= _BV(PCIE2);
    PCMSK2 |= _BV(BEAN_PCINT_D0);

    pinMode(0, INPUT_PULLUP);
    Bean.setLed(0,0,30);
}

void loop() {
    Bean.sleep(5000);
    Bean.setLed(0,0,30);    
    if (interruptSeen) {
        interruptSeen = false;
        if (digitalRead(0) == HIGH) {
            Bean.setLed(30,0,0);
        } else {
            Bean.setLed(0,30,0);
        }
    }
}

ISR(PCINT2_vect) {
    interruptSeen = true;
// Do nothing but wake me up
}