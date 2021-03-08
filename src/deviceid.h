#include <ArduinoUniqueID.h>
#include <sstream>
#include <iomanip>

class DeviceID
{
    std::string getUniqueID() const
    {
        std::stringstream stream;
        for (size_t i = 0; i < UniqueIDsize; ++i)
            stream << std::setfill('0') << std::setw(2) << std::hex << static_cast<unsigned long>(UniqueID[i]);
        return stream.str();
    }
public:
    const std::string id;
    DeviceID() : id(getUniqueID()) {}
};

const DeviceID deviceID;