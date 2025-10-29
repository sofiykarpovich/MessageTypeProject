#include <gtest/gtest.h>
#include <sstream>
#include <cereal/archives/json.hpp>
#include "MessageType.h"

TEST(MessageTypeTest, ToStringAndFromString)
{
    EXPECT_EQ(MessageTypeConverter::ToString(MessageType::System), "system");
    EXPECT_EQ(MessageTypeConverter::ToString(MessageType::Server), "server");
    EXPECT_EQ(MessageTypeConverter::ToString(MessageType::Session), "session");

    EXPECT_EQ(MessageTypeConverter::FromString("system"), MessageType::System);
    EXPECT_EQ(MessageTypeConverter::FromString("server"), MessageType::Server);
    EXPECT_EQ(MessageTypeConverter::FromString("session"), MessageType::Session);
}

TEST(MessageTypeTest, InvalidStringThrows)
{
    EXPECT_THROW(MessageTypeConverter::FromString("invalid_type"), std::invalid_argument);
}

TEST(MessageTypeTest, CerealSerialization)
{
    MessageType original = MessageType::Session;
    std::stringstream ss;

    {
        cereal::JSONOutputArchive archive(ss);
        archive(cereal::make_nvp("type", original));
    }

    MessageType restored;
    {
        cereal::JSONInputArchive archive(ss);
        archive(cereal::make_nvp("type", restored));
    }

    EXPECT_EQ(original, restored);
}
