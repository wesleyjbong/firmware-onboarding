#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // constants here!
    const int LEDPin = 13; // Pin for the built-in LED
    const unsigned long defaultInterval = 1000; // Default interval in milliseconds
    const uint8_t SPI_CS_PIN = 10; // Chip Select pin for SPI
    const long minTemp = -40; // Minimum temperature from BME280 sensor
    const long maxTemp = 85; // Maximum temperature from BME280 sensor
    const long minTempInterval = 500; // Interval for minimum temperature in milliseconds
    const long maxTempInterval = 75; // Interval for maximum temperature in milliseconds
}