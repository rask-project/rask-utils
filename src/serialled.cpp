#include "serialled.h"
#include "raskcore.h"
#include <Arduino.h>

Rask::SerialLed::SerialLed(uint8_t pin, uint64_t blinkInterval) : 
    m_pin(pin)
{
    pinMode(m_pin, OUTPUT);

    m_blinkObject.setInterval(blinkInterval);
    slotBlink.setSignalParent(&m_blinkObject.timeout);
    slotBlink.setCallback([&]() { digitalWrite(m_pin, !digitalRead(m_pin)); });
    
    m_blinkObject.timeout.connect(&slotBlink);
}

void Rask::SerialLed::on()
{
    digitalWrite(m_pin, HIGH);
}

void Rask::SerialLed::off()
{
    digitalWrite(m_pin, LOW);
}

void Rask::SerialLed::blinkOn()
{
    m_blinkObject.startTimer();
    RaskCore::addEvent(&m_blinkObject);
}

void Rask::SerialLed::blinkOff()
{
    m_blinkObject.stopTimer();
    RaskCore::removeEvent(&m_blinkObject);
}

void Rask::SerialLed::setIntervalBlink(uint64_t interval)
{
    m_blinkObject.setInterval(interval);
}
