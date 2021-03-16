#pragma once
#include <stdint.h>
#include "driver/gpio.h"

namespace Rask {
namespace GPIO {

typedef gpio_mode_t Mode;
typedef gpio_pull_mode_t PullMode;

class Pin
{
public:
    /**
     * @brief Construct a new Pin object
     * @param pin
     * @param mode
     */
    Pin(uint8_t pin, Mode mode = Mode::GPIO_MODE_INPUT_OUTPUT);

    enum class Level
    {
        LOW = 0x0,
        HIGH = 0x1
    };

    /**
     * @brief Set output level
     * @param level LOW: 0x0, WRITE: 0x1
     */
    void write(Pin::Level level);

    /**
     * @brief Set output level
     * @param level uint32_t
     */
    void write(uint32_t level);

    /**
     * @brief Get input level
     * @return int 
     */
    int read();

    /**
     * @brief Configure GPIO pull-up/pull-down resistors
     * @param mode
     */
    void setPullMode(PullMode mode);

protected:
    const uint8_t m_pinChar;
    const gpio_num_t m_pinGPIO;
    const Mode m_mode;
};

} // namespace GPIO
} // namespace Rask