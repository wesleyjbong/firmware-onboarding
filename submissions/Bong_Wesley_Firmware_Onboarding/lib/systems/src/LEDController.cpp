#include "LEDController.h"
#include <Arduino.h>

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

void LEDController::update() {
    unsigned long currentMillis = millis();
    
    // Check if enough time has passed based on current interval
    if (currentMillis - lastToggleTime >= interval) {
        lastToggleTime = currentMillis;
        ledState = !ledState; // Toggle state
        digitalWrite(pin, ledState);
    }
}
// Public method to set the interval between LED blinks
void LEDController::setSpeed(unsigned long newInterval) {
    interval = newInterval;
}
    

