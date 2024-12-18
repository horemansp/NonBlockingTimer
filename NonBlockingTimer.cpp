// NonBlockingTimer.cpp
#include "NonBlockingTimer.h"

// Constructor
NonBlockingTimer::NonBlockingTimer(unsigned long timeValue, char timeUnit, bool oneShot)
    : oneShot(oneShot), running(false) {
    if (timeUnit == 's') {
        duration = timeValue * 1000000UL; // Convert seconds to microseconds - UL stands for Unsigned Long
    } else if (timeUnit == 'u') {
        duration = timeValue; // Time is already in microseconds
    } else {
        duration = 1000000UL; // Default to 1 second
    }
    startTime = 0;
}

// Start the timer
void NonBlockingTimer::start() {
    startTime = micros();
    running = true;
}

// Check if the timer has lapsed
bool NonBlockingTimer::isLapsed() {
    if (!running) {
        return false; // Timer is not running
    }

    unsigned long elapsedTime = micros() - startTime;

    if (elapsedTime >= duration) {
        if (oneShot) {
            running = false; // Stop the timer if it's one-shot
        } else {
            startTime = micros(); // Reset the timer for continuous mode
        }
        return true;
    }
    return false;
}

// Reset the timer
void NonBlockingTimer::reset() {
    startTime = micros();
    running = true;
}

// Get the current value of the timer
unsigned long NonBlockingTimer::currentValue() const {
    if (!running) {
        return 0;
    }
    return micros() - startTime;
}

// Set a new duration for the timer
void NonBlockingTimer::setDuration(unsigned long timeValue, char timeUnit) {
    if (timeUnit == 's') {
        duration = timeValue * 1000000UL; // Convert seconds to microseconds
    } else if (timeUnit == 'u') {
        duration = timeValue; // Time is already in microseconds
    } else {
        duration = 1000000UL; // Default to 1 second
    }
}
