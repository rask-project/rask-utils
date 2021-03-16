#include "rask-pin.h"
#include <iostream>

namespace Rask {
namespace GPIO {

Pin::Pin(uint8_t pin, Mode mode) :
    m_pinChar(pin),
    m_pinGPIO(static_cast<gpio_num_t>(pin)),
    m_mode(mode)
{
    gpio_pad_select_gpio(m_pinChar);
    gpio_set_direction(m_pinGPIO, m_mode);
    gpio_set_level(m_pinGPIO, 0x0);
}

void Pin::write(Pin::Level level) 
{
    write(static_cast<uint32_t>(level));
}

void Pin::write(uint32_t level)
{
    try {
        gpio_set_level(m_pinGPIO, level);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

int Pin::read()
{
    return gpio_get_level(m_pinGPIO);
}

void Pin::setPullMode(PullMode mode)
{
    gpio_set_pull_mode(m_pinGPIO, mode);
}

} // namespace GPIO
} // namespace Rask