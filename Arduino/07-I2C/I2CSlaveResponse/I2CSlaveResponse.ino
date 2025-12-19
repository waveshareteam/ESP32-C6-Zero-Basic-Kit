/*
  I2C Slave Response

  Description: Responds to data requests from the I2C master device; this code is intended to be used with "I2cMasterRequest.ino".

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
  Wire.onRequest(requestEvent);     // Register event handler for data requests
}

void loop() {
  delay(100);
}

// Callback function for when master requests data
void requestEvent() {
  Wire.write((const uint8_t*)"hello", 5);  // Send 5 bytes ("hello") to the master
}