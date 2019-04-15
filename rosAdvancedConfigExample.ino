
/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

// This file is needed to fool the Arduino build system into lookning
// in .../Aduino/Libraries/ for other #include files.   The file ros_lib.h
// is empty except for a comment.
// Note the this is not needed if we use the system <ros.h> but is only
// needed if a local "ros.h" isused.
#include <ros_lib.h>


#include "ros.h" 
#include <std_msgs/String.h>


// On the Blue PillThe LED is between the power supply and the PC13 pin.
// So setting the PC13 pin LOW turns the LED on because PC13 is wired to
// "sink" current
#define LED_BUILTIN PC13
#define LED_ON  LOW
#define LED_OFF HIGH 
bool ledState;

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LED_ON);   
  ledState = true;
  
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();

  toggleLED();
  delay(1000);
}


void toggleLED() {
  if (ledState) {
    digitalWrite(LED_BUILTIN, LED_ON);   
  }
  else {
    digitalWrite(LED_BUILTIN, LED_OFF);
  }
  ledState = !ledState;
}
