#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController myLED(BMEConstants::LEDPin, BMEConstants::defaultInterval);

void setup()
{
    BMESPIInterfaceInstance::create();
    BMESPIInterface& SPIInterface = BMESPIInterfaceInstance::instance();
    bool connected = SPIInterface.connect();
    if (!connected) {
        while (1) {
            // Handle connection failure
        }
    }
    myLED.start();
}

void loop()
{
    // Code here!
    BMESPIInterface& SPIInterface = BMESPIInterfaceInstance::instance();
    float temp = SPIInterface.update();
    unsigned long newInterval = (85-temp)*10 - 80; // Calculate new interval based on temperature
    myLED.setSpeed(newInterval);
    myLED.update();
}
