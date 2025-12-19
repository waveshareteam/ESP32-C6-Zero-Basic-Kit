/*
  I2C Master Write

  Description: Sends data to the I2C slave device; this code is intended to be used with "I2cSlaveReceive.ino".

  Wiring:
    [Master Device]              [Slave Device]
    ESP32-C6-Zero                 ESP32-C6-Zero
    SDA (GPIO 2)       <------>   SDA (GPIO 19)
    SCL (GPIO 3)       <------>   SCL (GPIO 20)
    GND                <------>   GND

  Link:
  - Tutorial [ZH]: https://docs.waveshare.net/ESP32-Arduino-Tutorials/I2C-Communication
*/

#include <Wire.h>

#define SDA 2  // SDA pin
#define SCL 3  // SCL pin

byte x = 0;  // Counter variable

void setup() {
  Wire.begin(SDA, SCL, 100000);  // Initialize I2C master at 100kHz
}

void loop() {
  Wire.beginTransmission(8);               // Begin transmission to slave at address 8
  Wire.write((const uint8_t*)"x is ", 5);  // Send the string "x is " (5 bytes)
  Wire.write(x);                           // Send the value of x
  Wire.endTransmission();                  // End transmission

  x++;         // Increment the counter
  delay(500);  // Wait 500ms
}
