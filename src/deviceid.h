#include <ArduinoUniqueID.h>
#include <sstream>
#include <iomanip>

namespace Rask
{
/**
 * @brief Get unique string id
 */
class DeviceID
{
    /**
     * @brief Get the Unique ID string
     * @return std::string 
     */
    std::string getUniqueID() const
    {
        std::stringstream stream;
        for (size_t i = 0; i < UniqueIDsize; ++i)
            stream << std::setfill('0') << std::setw(2) << std::hex << static_cast<unsigned long>(UniqueID[i]);
        return stream.str();
    }
public:
    /**
     * @brief Unique ID string
     */
    const std::string id;

    /**
     * @brief Construct a new Device ID object
     */
    DeviceID() : id(getUniqueID()) {}
};
}

/**
 * @brief Global constant instance for DeviceID
 */
const Rask::DeviceID DeviceID;