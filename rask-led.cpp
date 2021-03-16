#include "rask-led.h"
#include "rask-utils.h"

#include <iostream>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

namespace Rask {
namespace GPIO {

Led::Led(uint8_t pin) :
    Pin(pin),
    m_stackDepth(1024),
    m_interval(),
    m_handle(nullptr)
{}

void Led::on()
{
    write(Pin::Level::HIGH);
}

void Led::off()
{
    write(Pin::Level::LOW);
}

void Led::blinkOff()
{
    if (m_handle == nullptr) {
        std::cerr << "Error: Led (" << Rask::Utils::pointerStr(this) << ") - Handle not defined\n";
        return;
    }
    
    vTaskDelete(m_handle);
    m_handle = nullptr;
}

int64_t Led::getInterval() const
{
    return m_interval.count();
}

void Led::blinkOn()
{
    xTaskCreate(&blink, "blinkLed", m_stackDepth, this, 1, &m_handle);
}

void Led::blink(void *p)
{
    auto *led = static_cast<Led *>(p);
    while (true)
    {
        led->write(!led->read());
        vTaskDelay(pdMS_TO_TICKS(led->getInterval()));
    }
}

} // namespace GPIO
} // namespace Rask
