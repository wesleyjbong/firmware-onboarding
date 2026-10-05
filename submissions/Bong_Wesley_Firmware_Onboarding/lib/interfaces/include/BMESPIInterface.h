#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() = default;

    bool connect();
    float update();
    
private:
    Adafruit_BME280 sensor{BMEConstants::SPI_CS_PIN};
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
