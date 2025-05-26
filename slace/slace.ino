#include <Wire.h>

#define MASTER_ADDRESS 8 
void setup() {
  Wire.begin(MASTER_ADDRESS); 
  Wire.onReceive(receiveEvent); // it is an event triggered when master sends data
  Serial.begin(9600);
  Serial.println("Slave Started");
}

void loop() {
  delay(1000);
}
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int receivedValue = Wire.read(); 
    Serial.print("Received: ");
    Serial.println(receivedValue);
  }
}