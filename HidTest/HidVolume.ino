void setup() {
  BeanHid.enable();
}

void loop() {
  AccelerationReading accel = Bean.getAcceleration();
  int16_t x = accel.xAxis;

  if (x > 100) {
    BeanHid.sendMediaControl(VOLUME_UP);
    Bean.setLed(255, 0, 0);
  } else if (x < -100) {
    BeanHid.sendMediaControl(VOLUME_DOWN);
    Bean.setLed(0, 255, 0);
  } else {
    Bean.setLed(0, 0, 0);
  }
  Bean.sleep(1000);
}