#pragma once

#include <raskobject.h>

namespace Rask
{
/**
 * @brief LedChannel - struct to get next channel
 */
struct LedChannel
{
    static uint8_t getNext();
private:
    static uint8_t m_channel;
};

/**
 * @brief LedConfig - struct for configuring dimmable LED
 */
struct LedConfig
{
    uint8_t pin;
    double frequence {5000};
    uint8_t resolution {8};
    uint8_t channel {LedChannel::getNext()};
};

/**
 * @brief SerialLedDimmer - class to send signals to the dimmed output
 */
class SerialLedDimmer
{
    const LedConfig m_output;
public:
    /**
     * @brief Construct a new Serial Led Dimmer object
     * @param output LedConfig object
     */
    SerialLedDimmer(const LedConfig output);

    /**
     * @brief Set the duty vaalue
     * @param duty 
     */
    void setDuty(uint32_t duty);

    /**
     * @brief Get the duty value
     * @return uint32_t 
     */
    uint32_t getDuty();
};
}