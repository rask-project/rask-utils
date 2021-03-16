#pragma once

#include "rask-pin.h"

namespace Rask {
namespace GPIO {

/**
 * @brief 
 */
class Led : public Pin
{
public:
    /**
     * @brief Construct a new Led object
     * @param pin 
     */
    Led(uint8_t pin);

    /**
     * @brief 
     */
    void on();

    /**
     * @brief
     */
    void off();

    /**
     * @brief 
     */
    void blinkOn();

    /**
     * @brief 
     */
    void blinkOff();

    /**
     * @brief Set the Blink Interval object
     * 
     */
    void setBlinkInterval();
};

} // namespace GPIO
} // namespace Rask
