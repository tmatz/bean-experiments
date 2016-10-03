#include <Wire.h>

#define I2CMotorDriverAddr        0x0f

#define MotorSpeedSet             0x82
#define PWMFrequenceSet           0x84
#define DirectionSet              0xaa
#define MotorSetA                 0xa1
#define MotorSetB                 0xa5
#define Nothing                   0x01
#define Stepernu                  0x1c

void MotorSpeedSetAB(
    unsigned char motorSpeedA,
    unsigned char motorSpeedB)
{
  motorSpeedA=map(motorSpeedA,0,100,0,255);
  motorSpeedB=map(motorSpeedB,0,100,0,255);
  Wire.beginTransmission(I2CMotorDriverAddr);
  Wire.write(MotorSpeedSet);
  Wire.write(motorSpeedA);
  Wire.write(motorSpeedB);
  Wire.endTransmission();
}

void MotorPWMFrequenceSet(
    unsigned char frequency)
{    
  Wire.beginTransmission(I2CMotorDriverAddr);
  Wire.write(PWMFrequenceSet);
  Wire.write(frequency);
  Wire.write(Nothing);
  Wire.endTransmission();
}

void MotorDirectionSet(
    unsigned char direction)
{
     //  Adjust the direction of the motors 0b0000 I4 I3 I2 I1
  Wire.beginTransmission(I2CMotorDriverAddr);
  Wire.write(DirectionSet);
  Wire.write(direction);
  Wire.write(Nothing);
  Wire.endTransmission();
}

void MotorDriectionAndSpeedSet(
    unsigned char direction,
    unsigned char motorSpeedA,
    unsigned char motorSpeedB)
{
  MotorDirectionSet(direction);
  MotorSpeedSetAB(motorSpeedA, motorSpeedB);  
}

void setup()
{
  Wire.begin();
  Bean.sleep(10);
  //Serial.begin(9600);
  //Serial.println("setup begin");
  //stepperrun();
}

void loop()
{
   while(1) {
    MotorSpeedSetAB(255, 255);
    Bean.sleep(10); //this delay needed

    MotorDirectionSet(0b1010);
    //"0b1010" defines the output polarity, "10" means the M+ is "positive" while the M- is "negative"
    // make sure M+ and M- is different polarity when driving DC motors.
    Bean.sleep(1000); 

    MotorDirectionSet(0b0101);  //0b0101  Rotating in the opposite direction
    Bean.sleep(500);
  }
}
