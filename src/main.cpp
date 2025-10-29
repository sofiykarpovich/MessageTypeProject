#include <iostream>
#include <sstream>
#include <cereal/archives/json.hpp>
#include "MessageType.h"

int main()
{
    MessageType type = MessageType::Server;

    std::stringstream ss;
    {
        cereal::JSONOutputArchive archive(ss);
        archive(cereal::make_nvp("message_type", type));
    }

    std::cout << "Serialized JSON:\n" << ss.str() << std::endl;

    MessageType deserializedType;
    {
        cereal::JSONInputArchive archive(ss);
        archive(cereal::make_nvp("message_type", deserializedType));
    }

    std::cout << "Deserialized Type: "
              << MessageTypeConverter::ToString(deserializedType)
              << std::endl;

    return 0;
}
