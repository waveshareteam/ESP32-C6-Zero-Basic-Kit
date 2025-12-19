/*
  I2C Slave Receive

  Description: Receives data from the I2C master device; this code is intended to be used with "I2cMasterWrite.ino".

  Wiring:
    [Slave Device]               [Master Device]
    ESP32-C6-Zero                 ESP32-C6-Zero
    SDA (GPIO 19)      <------>   SDA (GPIO 2)
    SCL (GPIO 20)      <------>   SCL (GPIO 3)
    GND                <------>   GND

  Link:
  - Tutorial [ZH]: https://docs.waveshare.net/ESP32-Arduino-Tutorials/I2C-Communication
*/

#include <Wire.h>

#define SDA 19  // SDA pin
#define SCL 20  // SCL pin

void setup() {
  Wire.begin(8, SDA, SCL, 100000);  // Initialize I2C slave at address 8, 100kHz
  Wire.onReceive(receiveEvent);     // Register event handler for received data
  Serial.begin(9600);               // Initialize serial communication
}

void loop() {
  delay(100);
}

// Callback function for when data is received from master
void receiveEvent(int len) {
  while (Wire.available() > 1) {  // Read all bytes except the last one (the string part)
    char c = Wire.read();
    Serial.print(c);
  }
  int x = Wire.read();  // Read the last byte (the number)
  Serial.println(x);    // Print the number and a newline
}