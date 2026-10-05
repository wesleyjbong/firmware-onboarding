#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController myLED(BMEConstants::LEDPin, BMEConstants::defaultInterval);

void setup()
{
    BMEI2CInterfaceInstance::create();
    BMEI2CInterface& I2CInterface = BMEI2CInterfaceInstance::instance();
    bool connected = I2CInterface.connect();
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
    BMEI2CInterface& I2CInterface = BMEI2CInterfaceInstance::instance();
    float temp = I2CInterface.update();
    unsigned long newInterval = (85-temp)*10 - 80; // Calculate new interval based on temperature
    myLED.setSpeed(newInterval);
    myLED.update();
}
