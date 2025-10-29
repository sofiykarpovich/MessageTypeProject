#pragma once
#include <string>
#include <stdexcept>
#include <cereal/types/string.hpp>

enum class MessageType
{
    System,
    Server,
    Session
};

class MessageTypeConverter
{
public:
    static std::string ToString(MessageType type);
    static MessageType FromString(const std::string& str);
};

namespace cereal
{
    template <class Archive>
    void save(Archive& ar, const MessageType& type)
    {
        std::string str = MessageTypeConverter::ToString(type);
        ar(str);
    }

    template <class Archive>
    void load(Archive& ar, MessageType& type)
    {
        std::string str;
        ar(str);
        type = MessageTypeConverter::FromString(str);
    }
}
