void setup() {
  BeanHid.enable();
  // Serial port is initialized automatically; we don't have to do anything
}

int volume = 0;

void loop() {
  AccelerationReading accel = Bean.getAcceleration();
  int16_t x = accel.xAxis;
  int16_t y = accel.yAxis;
  // Add a deadzone. If Bean is reasonabally flat, don't move the mouse pointer
  if (abs(x) < 20) { x = 0; }
  if (abs(y) < 20) { y = 0; }
   // we want to map the movements to reasonable values.
   // This constrains the accelerometer to -20 to 20.
  int16_t mousey = map(x, -60, 60, -20, 20);
  int16_t mousex = map(y, -60, 60, 20, -20);
  BeanHid.moveMouse(mousex, mousey);
  
  if (volume == 0) {
    BeanHid.sendMediaControl(VOLUME_UP);
    volume = 1;
  } else {
    BeanHid.sendMediaControl(VOLUME_DOWN);
    volume = 0;
  }

  Bean.sleep(100);
}