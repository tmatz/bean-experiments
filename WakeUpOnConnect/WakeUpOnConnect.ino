void setup() {
  Bean.enableConfigSave(false);
  Bean.enableWakeOnConnect(true);
 }
 
 void loop() {
   bool connect =Bean.getConnectionState();
   if (connect) {
     Bean.setLed(0, 255, 0);
   } else {
     Bean.setLed(0, 0, 0);
   }
   Bean.sleep(0xFFFFFFFF);
  }
