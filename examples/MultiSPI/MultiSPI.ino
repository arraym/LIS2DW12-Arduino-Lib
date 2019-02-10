/******************************************************************************
MultiSPI.ino

Ion Bold
October 18 , 2018

Description:
Example using up to two LIS2DW12s on the same SPI channel, with different CS pins.
If only one sensor is attached, this sketch reports failure on that channel and
runs with the single sensor instead.

Resources:
Uses Wire.h for i2c operation
Uses SPI.h for SPI operation
Either can be omitted if not used

Development environment specifics:
Arduino IDE 1.8.5

Hardware connections
***CAUTION -- SPI pins can not be connected directly to 5v IO***

Connect SDA/SDI lines to pin 11 through level shifters (MOSI)
Connect SCL pin lines to pin 13 through level shifters (SCLK)
Connect SDO/SA0 lines to pin 12 through level shifters (MISO)
Connect CS to free pins through level shifters.  This example uses 9 and 10.
Connect GND and ***3.3v*** power to the IMU.  The sensors are not 5v tolerant.

(Multiple SPI devices share pins except for the Chip Select lines which
are unique for each device on the bus.)

Distributed as-is; no warranty is given.
******************************************************************************/

#include <LIS2DW12.h>
#include "Wire.h"
#include "SPI.h"

//Create two instances of the driver class
LIS2DW12 SensorOne( SPI_MODE, 10, SPISettings(250000, MSBFIRST, SPI_MODE3) );
LIS2DW12 SensorTwo( SPI_MODE, 9, SPISettings(250000, MSBFIRST, SPI_MODE3) );


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000); //relax...
  Serial.println("Processor came out of reset.\n");
  
  //Call .begin() to configure the IMUs
  if( SensorOne.begin() != 0 )
  {
	  Serial.println("Problem starting the sensor with CS @ Pin 10.");
  }
  else
  {
	  Serial.println("Sensor with CS @ Pin 10 started.");
  }
  if( SensorTwo.begin() != 0 )
  {
	  Serial.println("Problem starting the sensor with CS @ Pin 9.");
  }
  else
  {
	  Serial.println("Sensor with CS @ Pin 9 started.");
  }
  
}


void loop()
{
  //Get all parameters
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X1 = ");
  Serial.println(SensorOne.readFloatAccelX(), 4);
  Serial.print(" Y1 = ");
  Serial.println(SensorOne.readFloatAccelY(), 4);
  Serial.print(" Z1 = ");
  Serial.println(SensorOne.readFloatAccelZ(), 4);
  Serial.print(" X2 = ");
  Serial.println(SensorTwo.readFloatAccelX(), 4);
  Serial.print(" Y2 = ");
  Serial.println(SensorTwo.readFloatAccelY(), 4);
  Serial.print(" Z2 = ");
  Serial.println(SensorTwo.readFloatAccelZ(), 4);

  Serial.print("\nThermometer:\n");
  Serial.print(" Degrees C1 = ");
  Serial.println(SensorOne.readTempCLowRes(), 4);
  Serial.print(" Degrees F1 = ");
  Serial.println(SensorOne.readTempFLowRes(), 4);
  Serial.print(" Degrees C2 = ");
  Serial.println(SensorTwo.readTempCLowRes(), 4);
  Serial.print(" Degrees F2 = ");
  Serial.println(SensorTwo.readTempFLowRes(), 4);
  
  Serial.print("\nSensorOne Bus Errors Reported:\n");
  Serial.print(" All '1's = ");
  Serial.println(SensorOne.allOnesCounter);
  Serial.print(" Non-success = ");
  Serial.println(SensorOne.nonSuccessCounter);
  Serial.print("SensorTwo Bus Errors Reported:\n");
  Serial.print(" All '1's = ");
  Serial.println(SensorTwo.allOnesCounter);
  Serial.print(" Non-success = ");
  Serial.println(SensorTwo.nonSuccessCounter);
  delay(1000);
}
