/******************************************************************************
MinimalistExample.ino

Ion Bold
October 18 , 2018

Description:
Most basic example of use.

Example using the LIS2DW12 with basic settings.  This sketch collects
Accelerometer and Temperature sensor data every second, then presents it on the serial monitor.

Resources:
Uses Wire.h for i2c operation
Uses SPI.h for SPI operation
Either can be omitted if not used

Development environment specifics:
Arduino IDE 1.8.5

Hardware connections:
Connect I2C SDA line to A4
Connect I2C SCL line to A5
Connect GND and 3.3v power to the IMU

Distributed as-is; no warranty is given.
******************************************************************************/
#include <LIS2DW12.h>
#include "SPI.h"

#define SPEED     62500

LIS2DW12 myIMU(SPI_MODE, 10, SPISettings(SPEED, MSBFIRST, SPI_MODE3)); //Default constructor is I2C, addr 0x19

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000); //relax...
  Serial.println("Processor came out of reset.\n");
  
  SPI.begin();
  myIMU.begin();
}


void loop()
{
  //Get all parameters
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X = ");
  Serial.println(myIMU.readFloatAccelX(), 4);
  Serial.print(" Y = ");
  Serial.println(myIMU.readFloatAccelY(), 4);
  Serial.print(" Z = ");
  Serial.println(myIMU.readFloatAccelZ(), 4);

  Serial.print("\nThermometer low resolution (8bit):\n");
  Serial.print(" Degrees C = ");
  Serial.println(myIMU.readTempCLowRes(), DEC);
  Serial.print(" Degrees F = ");
  Serial.println(myIMU.readTempFLowRes(), DEC);
  
  delay(2000);
}
