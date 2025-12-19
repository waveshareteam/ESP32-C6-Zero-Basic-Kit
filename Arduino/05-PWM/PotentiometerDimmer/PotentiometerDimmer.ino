/*
  PWM Potentiometer Dimmer

  Description: Dim an LED based on the position of a potentiometer.

  Wiring:
  - ESP32-C6-Zero
  - LED -> GPIO 22
  - Potentiometer -> GPIO 4

  Link:
  - Tutorial [ZH]: https://docs.waveshare.net/ESP32-Arduino-Tutorials/PWM
*/

const int ledPin = 22;            // Pin connected to the LED
const int potentiometerPin = 4;  // Pin connected to the potentiometer

int potentiometerValue;  // Raw ADC reading from the potentiometer
int brightness;          // Mapped brightness value for PWM

void setup() {
}

void loop() {
  // 1. Read the potentiometer analog value (range 0–4095)
  potentiometerValue = analogRead(potentiometerPin);

  // 2. Map ADC reading to PWM range (0–255)
  brightness = map(potentiometerValue, 0, 4095, 0, 255);

  // 3. Set LED brightness using the mapped value
  analogWrite(ledPin, brightness);

  delay(20);
}