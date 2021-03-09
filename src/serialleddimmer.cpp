#include "serialleddimmer.h"
#include <iostream>

uint8_t Rask::LedChannel::m_channel {0};

uint8_t Rask::LedChannel::getNext()
{
    return m_channel++;
}

Rask::SerialLedDimmer::SerialLedDimmer(const LedConfig output) :
    m_output(output)
{
    ledcSetup(m_output.channel, m_output.frequence, m_output.resolution);
    ledcAttachPin(m_output.pin, m_output.channel);
}

void Rask::SerialLedDimmer::setDuty(uint32_t duty)
{
    ledcWrite(m_output.channel, duty);
}

uint32_t Rask::SerialLedDimmer::getDuty()
{
    return ledcRead(m_output.channel);
}