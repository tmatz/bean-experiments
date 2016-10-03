#define PIN 0

void setup() {
    pinMode(PIN, INPUT_PULLUP);
}

void loop() {
  Bean.setLed(0,0,0);    
  Bean.sleep(5000);
  if (digitalRead(PIN) == HIGH) {
    Bean.setLed(30,0,0);
  } else {
    Bean.setLed(0,30,0);
  }
  Bean.sleep(100);
}
