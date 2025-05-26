#include <Wire.h>

String receivedData = "";
char serialData[10];

void setup() {
  Wire.begin(8);                 // Join I2C bus as Slave with address 8
  Wire.onReceive(receiveEvent);  // Register event to receive data from master
  Wire.onRequest(requestEvent);  // Register event to send data to master
  Serial.begin(9600);            // Start Serial Monitor
}

void loop() {
  // Slave waits for user input to send data to master
  if (Serial.available()) {

    receivedData = Serial.readString();
    strcpy(serialData, receivedData.c_str());
    Serial.println("Sent to Master: " + receivedData);
  }

  //delay(500);
}

// Function to receive data from Master
void receiveEvent(int howMany) {
  String message = "";
  while (Wire.available()) {
    message += (char)Wire.read();
  }
  Serial.println("Received from Master: " + message);
}

// Function to send stored data to Master when requested
void requestEvent() {
  Serial.print("Converted Data: ");
  Serial.println(serialData);
  for (int i = 0; i < 7; i++)
    Wire.write(serialData[i]);
    //delay(500);  // Send stored message to Master
                                // receivedData = "A"; // need to clear last data when sent otherwise it is printed in master side
}
