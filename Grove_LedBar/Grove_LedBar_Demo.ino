#define ROTARY_ANGLE_SENSOR A3 // The input pin used for the sensor
#define ADC_REF 5 // This matches the operating voltage we set to 5V
#define GROVE_VCC 5 // VCC of the grove interface which is often 5V
#define NUM_OF_LEDS 10 // Number of LEDs in the LED bar

#include <Grove_LED_Bar.h>

Grove_LED_Bar LEDbar(A4, A5, 1); // Setting the data and clock pins used

void setup() 
{
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  LEDbar.begin();
}

void loop() 
{
  // Measure the number of LEDs that should be on
  // based on the angle of the rotary sensor
  int lightLevel = getLightLevel();

  // If light level is above 0, set LED bar accordingly
  if (lightLevel) {
    
    // Turn on the LEDs up to the measured light level
    for (int i = 1; i <= lightLevel; i++) {
        // Turn on 
        LEDbar.setLed(i, 1);
        delay(100);
    }
    
    // Turn off the rest of the LEDs in reverse order
    for (int j = 10; j > lightLevel; j--) {
        // Turn off 
        LEDbar.setLed(j, 0);
        delay(100);
    }
    
  } else {
    
    // Turn off all LEDs 
    for (int k = 1; k <= 10; k++) {
        // Turn off
        LEDbar.setLed(k, 0);
    }
  }
}

int getLightLevel()
{
  // Take reading, measure voltage, and calculate 
  // number of LEDs which should be turned on
  int reading = analogRead(ROTARY_ANGLE_SENSOR); 
  float voltage = (float)reading*ADC_REF/1023;
  float level = (voltage*NUM_OF_LEDS)/GROVE_VCC;
  return level;
}
