#include <Arduino.h>

class LEDController
{
public:
    LEDController(int pinNum, unsigned long startDelay);
    void start();
    void update();
    void setSpeed(unsigned long newInterval);
private:
    int pin;
    unsigned long lastToggleTime;
    bool ledState;
    unsigned long interval; // Speed control variable
};
