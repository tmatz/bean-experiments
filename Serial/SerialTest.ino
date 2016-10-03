void setup() {
}

void loop() {
  Serial.print("Hello, I'm ");
  Serial.println(Bean.getBeanName());
  Bean.sleep(1000);
}