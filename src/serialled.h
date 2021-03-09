#pragma once

#include <raskobject.h>

namespace Rask
{
/**
 * @brief SerialLed - class to send on and off signal to serial pin
 */
class SerialLed
{
    uint8_t m_pin;
    RaskObject m_blinkObject;

public:
    enum class Type
    {
        Digital,
        Analog
    };

    /**
     * @brief Construct a new Serial Led object
     * @param pin Output pin
     * @param blinkInterval Interval to blink the led
     */
    SerialLed(uint8_t pin, uint64_t blinkInterval = 1000);

    /**
     * @brief Turn on the led
     */
    void on();
    /**
     * @brief Turn off the led
     */
    void off();

    /**
     * @brief Turn on the flashing led
     */
    void blinkOn();
    /**
     * @brief Turn off the flashing led
     */
    void blinkOff();

    /**
     * @brief Set the Interval Blink object
     * @param interval uint64_t in ms
     */
    void setIntervalBlink(uint64_t interval);

private:
/* private slots */
    RaskSlot<> slotBlink;
};
}
