"""
REPL LED Control

Description: Controls an LED via commands entered in the REPL ('on'/'off').

Wiring:
- ESP32-C6-Zero
- LED -> GPIO 22

Link:
- Tutorial [ZH]: https://docs.waveshare.net/ESP32-MicroPython-Tutorials/UART-Communication#repl-control-led
"""

import sys
from machine import Pin

# Define pin
LED_PIN = 22

# Initialize pin
led = Pin(LED_PIN, Pin.OUT)

print("System Ready. Please enter 'on' or 'off':")

while True:
    # input() pauses program execution, waits for user to enter a line and press Enter
    # This is the simplest way to receive commands from computer via REPL
    command = input()

    if command == "on":
        # If input is "on", turn on LED
        led.value(1)
        print("LED is ON")
    elif command == "off":
        # If input is "off", turn off LED
        led.value(0)
        print("LED is OFF")
    else:
        print("Unknown command. Please enter 'on' or 'off'.")