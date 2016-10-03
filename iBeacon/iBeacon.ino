void setup() {
  Bean.enableConfigSave(false);
  Bean.setAdvertisingInterval(1000);
  Bean.setBeaconParameters(0xDEAD, 0xBEEF, 0xCAFE);
  Bean.setBeaconEnable(true);
}
 
void loop() {
  Bean.sleep(0xFFFFFFFF);
}
