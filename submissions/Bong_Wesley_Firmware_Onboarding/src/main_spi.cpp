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
     // Calculate new interval based on temperature
    unsigned long newInterval = map((long)temp, BMEConstants::minTemp, BMEConstants::maxTemp, BMEConstants::minTempInterval, BMEConstants::maxTempInterval);
    myLED.setSpeed(newInterval);
    myLED.update();
}
