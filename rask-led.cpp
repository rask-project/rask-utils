#include "rask-led.h"

namespace Rask {
namespace GPIO {

Led::Led(uint8_t pin) :
    Pin(pin)
{}

void Led::on()
{
    write(Pin::Level::HIGH);
}

void Led::off()
{
    write(Pin::Level::LOW);
}

void Led::blinkOn()
{}

void Led::blinkOff()
{}

void Led::setBlinkInterval()
{}

} // namespace GPIO
} // namespace Rask
