#pragma once
#include <stdint.h>
#include <driver/ledc.h>

namespace Rask {
namespace GPIO {

typedef ledc_mode_t SpeedMode;
typedef ledc_timer_bit_t Resolution;

/**
 * @brief 
 */
struct LedDimmerChannel
{
    /**
     * @brief Get the next channel
     * @return uint8_t
     */
    static uint8_t getNext();
private:
    static uint8_t m_channel;
};

/**
 * @brief 
 */
struct LedDimmerConfig
{
    uint8_t pin;
    uint32_t frequence {5000};
    Resolution resolution {Resolution::LEDC_TIMER_8_BIT};
    uint8_t channel {LedDimmerChannel::getNext()};
    SpeedMode speedMode {SpeedMode::LEDC_LOW_SPEED_MODE};
};

/**
 * @brief 
 */
class LedDimmer
{
    const LedDimmerConfig m_config;
    ledc_timer_config_t m_ledcTimer;
    ledc_channel_config_t m_channelConfig;

public:
    /**
     * @brief Construct a new Led Dimmer object
     * @param config 
     */
    LedDimmer(const LedDimmerConfig &config);

    /**
     * @brief Set the duty vaalue
     * @param duty 
     */
    int setDuty(uint32_t duty);

    /**
     * @brief Get the duty value
     * @return uint32_t 
     */
    uint32_t getDuty() const;
};

} // namespace GPIO
} // namespace Rask
