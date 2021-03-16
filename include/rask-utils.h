#pragma once

#include <typeinfo>
#include <sstream>

namespace Rask {
namespace Utils {

template <typename obj>
std::string pointerStr(obj *event)
{
    const void *address = static_cast<const void *>(event);
    std::stringstream addr;
    addr << address;
    return addr.str();
}

} // Utils
} // Rask