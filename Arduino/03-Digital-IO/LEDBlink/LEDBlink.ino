/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Wiring:
  - ESP32-C6-Zero
  - LED -> GPIO 22
  
  Link:
  - Tutorial [ZH]: https://docs.waveshare.net/ESP32-Arduino-Tutorials/Digital-IO#digital-output
*/

const int ledPin = 22;  // Pin connected to the LED

// Runs once when the board powers up or resets
void setup() {
  // Set pin as output
  pinMode(ledPin, OUTPUT);
}

// Runs repeatedly in an infinite loop
void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED on (HIGH = voltage applied)
  delay(1000);                 // Wait one second
  digitalWrite(ledPin, LOW);   // Turn LED off
  delay(1000);                 // Wait one second
}