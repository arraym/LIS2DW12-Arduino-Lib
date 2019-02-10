/******************************************************************************
InterruptHWTapConfig.ino

Ion Bold
October 18 , 2018

Description:
Example using the LIS2DW12 interrupts.

This sketch demonstrates one way to detect single and double-tap events using
hardware interrupt pins. The LIS2DW12 pulses the int1 line once after the first
tap, then again if a second tap comes in.

The configuration is determined by reading the LIS2DW12 datasheet and application
note, then driving hex values to the registers of interest to set the appropriate
bits.

Resources:
Uses Wire.h for i2c operation
Uses SPI.h for SPI operation

Development environment specifics:
Arduino IDE 1.8.5

Hardware connections:
Connect I2C SDA line to A4
Connect I2C SCL line to A5
Connect GND and 3.3v power to the IMU
Connect INT1 to pin 2 -- Note:  the atmega has 5v input and the LIS2DW12 is 3.3v
output.  This is OK because the input is high impedance and 3.3v is a logic '1'
for 5v processors.  The signal is correctly detected and nothing is damaged.

Do not configure pin 2 as OUTPUT!

Distributed as-is; no warranty is given.
******************************************************************************/

#include <LIS2DW12.h>
#include "SPI.h"

#define SPEED     62500

//Interrupt variables
#define int1Pin 2  //Use pin 2 for int.0 on uno
uint8_t int1Status = 0;
uint8_t   result;

LIS2DW12 myIMU(SPI_MODE, 10, SPISettings(SPEED, MSBFIRST, SPI_MODE3)); //Default constructor is I2C, addr 0x19

void setup()
{
	Serial.begin(9600);
	delay(1000); //relax...
	Serial.println("Processor came out of reset.\n");

	//Call .beginCore() to configure the IMU
	if( myIMU.begin() != 0 )
	{
		Serial.print("Error at beginCore().\n");
	}
	else
	{
		Serial.print("\nbeginCore() passed.\n");
	}

	if( myIMU.initDoubleTap(3) )            // 0: only X axis, 1: only Y axis, 2: only Z axis, >2: all axis
	{
		Serial.println("Problem configuring the device.");
	}
	else
	{
		Serial.println("Device O.K.");
	}	

	//Configure the atmega interrupt pin
	pinMode(int1Pin, INPUT);
	attachInterrupt(digitalPinToInterrupt(int1Pin), int1ISR, LOW);
	
}


void loop()
{
	if(int1Status)  //If ISR has been serviced at least once
	{
		Serial.print("Double-tap event\n");
    myIMU.readRegister(&result, 0x3B);
    //Clear the ISR counter
    int1Status = 0;
	}
}


void int1ISR()
{
	//Serial.println("Interrupt serviced.");
	int1Status = 1;
}
