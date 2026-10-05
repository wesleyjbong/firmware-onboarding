#include "BMEI2CInterface.h"

bool BMEI2CInterface::connect() {
    return sensor.begin();
}

float BMEI2CInterface::update() {
    return sensor.readTemperature();
}