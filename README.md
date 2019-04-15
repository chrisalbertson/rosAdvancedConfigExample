# ROS Serial Advanced Configuration (working) Example

The example program in the ROS tutorial wiki does not work.  At least it does not work with a recent version of the Arduino IDE and a generic STM32F103 board commonly called the "Blue Pill"

This example code fixes a couple problems:

1. The Arduino gets the #include path wrong and

2. No data is written to the USB serial port so nothing gets published.

### Solutions implemented here:
1. Make a dummy file "ros_lib.h" that has just a comment in it.  Place this file in the same directory as <ros.h> and #include this file in the main sketch file.
2. In ArudioHardware.h add "#define SERIAL_CLASS USBSerial" and be sure to use an ST-Link (NOT a FIDDI dongle to upload the image.)

