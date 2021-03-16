#pragma once

#include "rask-pin.h"
#include <chrono>

namespace Rask {
namespace GPIO {

/**
 * @brief 
 */
class Led : public Pin
{
    const uint32_t m_stackDepth;
    std::chrono::milliseconds m_interval;
    void* m_handle;

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
     * @param interval 
     */
    template <typename Rep, typename Period>
    void blinkOn(std::chrono::duration<Rep, Period> interval)
    {
        m_interval = std::chrono::milliseconds(interval);
        blinkOn();
    }

    /**
     * @brief 
     */
    void blinkOff();

    /**
     * @brief Get the interval
     * @return int64_t 
     */
    int64_t getInterval() const;

private:
    /**
     * @brief 
     */
    void blinkOn();

    /**
     * @brief 
     * @param parameter 
     */
    static void blink(void *parameter);
};

} // namespace GPIO
} // namespace Rask
