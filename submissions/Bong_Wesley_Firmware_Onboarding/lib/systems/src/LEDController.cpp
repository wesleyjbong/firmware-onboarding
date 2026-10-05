#include "LEDController.h"
#include <Arduino.h>


// Constructor initializes the pin and starting speed
LEDController::LEDController(int pinNum, unsigned long startDelay) {
    pin = pinNum;
    interval = startDelay;
    lastToggleTime = 0;
    ledState = LOW;
}
void LEDController::start() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, ledState);
}
// Call this repeatedly in the main loop
void LEDController::update() {
    unsigned long currentMillis = millis();
    
    // Check if enough time has passed based on current interval
    if (currentMillis - lastToggleTime >= interval) {
        lastToggleTime = currentMillis;
        ledState = !ledState; // Toggle state
        digitalWrite(pin, ledState);
    }
}
// Public method to dynamically change the blink speed
void LEDController::setSpeed(unsigned long newInterval) {
    interval = newInterval;
}
    

