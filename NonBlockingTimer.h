// NonBlockingTimer.h
#ifndef NONBLOCKINGTIMER_H
#define NONBLOCKINGTIMER_H

#include <Arduino.h>

class NonBlockingTimer {
public:
    // Constructor
    NonBlockingTimer(unsigned long timeValue, char timeUnit = 's', bool oneShot = false);

    // Methods
    void start();
    bool isLapsed();
    void reset();
    unsigned long currentValue() const;
    void setDuration(unsigned long timeValue, char timeUnit = 's'); 

private:
    unsigned long duration;  // Timer duration in microseconds
    unsigned long startTime; // Start time in microseconds
    bool oneShot;            // Whether the timer is one-shot
    bool running;            // Timer state
};

#endif // NONBLOCKINGTIMER_H
