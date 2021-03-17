#include "rask-leddimmer.h"
#include <iostream>

namespace Rask {
namespace GPIO {

uint8_t LedDimmerChannel::m_channel {0};

uint8_t LedDimmerChannel::getNext()
{
    constexpr uint8_t limit {7};
    if (m_channel > limit)
        std::cout << "Channel Limit {0 - 7} = " << static_cast<short>(m_channel) << '\n';
    return m_channel++;
}

LedDimmer::LedDimmer(const LedDimmerConfig &config) :
    m_config(config),
    m_ledcTimer(ledc_timer_config_t {
        .speed_mode = config.speedMode,
        .duty_resolution = config.resolution,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = config.frequence,
        .clk_cfg = LEDC_AUTO_CLK
    }),
    m_channelConfig(ledc_channel_config_t {
        .gpio_num = config.pin,
        .speed_mode = config.speedMode,
        .channel = static_cast<ledc_channel_t>(config.channel),
        .intr_type = LEDC_INTR_FADE_END,
        .timer_sel = LEDC_TIMER_0,
        .duty = 0,
        .hpoint = 0
    })
{
    ledc_timer_config(&m_ledcTimer);
    ledc_channel_config(&m_channelConfig);
    ledc_fade_func_install(0);
}

int LedDimmer::setDuty(uint32_t duty)
{
    return ledc_set_duty_and_update(m_channelConfig.speed_mode, m_channelConfig.channel, duty, 0);
}

uint32_t LedDimmer::getDuty() const
{
    // return ledcRead(m_config.channel);
    return 0;
}

} // namespace GPIO
} // namespace Rask
