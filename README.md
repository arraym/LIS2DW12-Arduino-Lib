LIS2DW12 Arduino Library
========================

![LIS2DW12]

[*LIS2DW12 (SEN-13339)*]

This is an arduino IDE library to control the LIS2DW12.  It can be configured to use I2C or SPI with 2 instances per I2C channel or any number of SPI instances.  The top-level driver, class LIS2DW12, contains an inner driver LIS2DW12Core, a settings struct, and float-based math functions for conversion from raw to meaningful numbers.

This has been tested with Arduino Nano architecture.

Repository Contents
-------------------

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE. 
* **/src** - Source files for the library (.cpp, .h).
* **library.properties** - General library properties for the Arduino package manager. 

Example Briefs
--------------

* InterruptHWTapConfig - Embedded function demonstrating tap and double-tap detection
* MinimalistExample - The **easiest** configuration
* MultiI2C - Using two LIS2DW12s over I2C
* MultiSPI - Using two LIS2DW12s over SPI

Documentation
--------------

* **[Installing an Arduino Library Guide] - Basic information on how to install an Arduino library.
* **[Product Repository] - Main repository (including hardware files) for the LIS2DW12 Breakout.
* **[Hookup Guide] - Basic hookup guide for the LIS2DW12 Breakout.

Products that use this Library 
---------------------------------

* LIS2DW12 board

Version History
---------------

* [V 1.0.0]-- Initial commit of Arduino 1.8-compatible library.

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.


