#include <Wire.h>

#define SLAVE_ADDRESS 8 

void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
  Serial.println("Master Started");
}

void loop() {
  // Data to send
  int value = analogRead(A0); 
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write(value);
  Wire.endTransmission();
  Serial.print("Sending: ");
  Serial.println(value);
  delay(1000);
}