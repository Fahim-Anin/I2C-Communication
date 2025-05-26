#include <Wire.h>

uint32_t prevtime = millis();
uint32_t prevtime2 = millis();
String rcvData;

void setup() {
  Wire.begin(8);  // Initialize I2C as Master
  Serial.begin(9600);
}

void loop() {
  //  Master sends data to Slave
  if (Serial.available()) {
    String data = Serial.readString();
    Wire.beginTransmission(8);  // Start communication with slave(slave address: 8)
    Wire.write(data.c_str());   // Send data
    Wire.endTransmission();     //end transmission
    Serial.println("Sent to Slave: " + data);
    //delay(500);
  }

  // Master reads data from Slave
  // Wire.requestFrom(8, 1);
  // if(Wire.available())
  // {

  // char c = Wire.read();
  // Serial.println(c);

  // }
  // delay(500);
  if (millis() - prevtime2 > 1000) {
    prevtime2 = millis();
    Serial.println(rcvData);
  }
  Wire.requestFrom(8, 20);
  while (Wire.available() && millis() - prevtime > 500) {
    prevtime = millis();
    char c = Wire.read();
    rcvData += c;
    // if (c != 0)
    Serial.print(c);
  }

  //delay(500);
}