/*
  Button Control LED

  Turns an LED on when the button is pressed, and off when it is released.

  Wiring:
  - ESP32-C6-Zero
  - LED -> GPIO 22
  - Button -> GPIO 21
  
  Link:
  - Tutorial [ZH]: https://docs.waveshare.net/ESP32-Arduino-Tutorials/Digital-IO#digital-io-exercise
*/

const int ledPin = 22;     // LED pin
const int buttonPin = 21;  // Button pin
int buttonState;          // Button state variable

void setup() {
  pinMode(ledPin, OUTPUT);           // Set LED pin as output mode
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as pull-up input mode
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read button state

  if (buttonState == LOW) {      // When button is pressed (LOW)
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {                       // When button is not pressed (HIGH)
    digitalWrite(ledPin, LOW);   // Turn off LED
  }
}