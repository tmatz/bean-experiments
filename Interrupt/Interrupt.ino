#define BUTTON 12

void setup() {
   pinMode(BUTTON, INPUT);
   attachInterrupt(
       digitalPinToInterrupt(BUTTON), pinChanged, CHANGE);
}

void loop() {
  Bean.sleep(0xFFFFFFFF);
  bool val = digitalRead(BUTTON);
  if (val) {
     Bean.setLed(255, 0, 0);
  } else {
     Bean.setLed(0, 255, 0);
  }
  Bean.sleep(100);
  Bean.setLed(0, 0, 0);
}

void pinChanged() {
}