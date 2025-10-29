#include "MessageType.h"
#include <magic_enum.hpp>

std::string MessageTypeConverter::ToString(MessageType type)
{
    auto name = magic_enum::enum_name(type);
    if (name.empty())
    {
        throw std::invalid_argument("Unknown MessageType");
    }
    std::string result(name);
    for (auto& c : result)
        c = static_cast<char>(std::tolower(c));
    return result;
}

MessageType MessageTypeConverter::FromString(const std::string& str)
{
    std::string lower = str;
    for (auto& c : lower)
        c = static_cast<char>(std::tolower(c));

    for (auto type : magic_enum::enum_values<MessageType>())
    {
        if (ToString(type) == lower)
            return type;
    }

    throw std::invalid_argument("Invalid string for MessageType: " + str);
}
