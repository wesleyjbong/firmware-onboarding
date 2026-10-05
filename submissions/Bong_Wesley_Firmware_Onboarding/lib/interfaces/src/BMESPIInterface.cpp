#include "BMESPIInterface.h"

bool BMESPIInterface::connect() {
    return sensor.begin();
}

float BMESPIInterface::update() {
    return sensor.readTemperature();
}