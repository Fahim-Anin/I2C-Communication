// Wire Peripheral Sender
// by Nicholas Zambetti [http://www.zambetti.com](http://www.zambetti.com)

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI peripheral device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, as it is called when master calls and as loop runs always so this event is declared separatly

//if this function wrote in loop i2c keeps sending data even the master donot ask data
void requestEvent() {
  Wire.write("hello "); // respond with message of 6 bytes
  // as expected by master
}