#pragma once


#include <string>
#include <string_view>
#include <iosfwd>


namespace messaging {


enum class MessageType {
System,
Server,
Session
};


[[nodiscard]] std::string ToString(MessageType type);
[[nodiscard]] bool FromString(std::string_view text, MessageType& out) noexcept;


[[nodiscard]] inline std::string Serialize(MessageType type) { return ToString(type); }
[[nodiscard]] inline bool Deserialize(std::string_view text, MessageType& out) noexcept { return FromString(text, out); }


std::ostream& operator<<(std::ostream& os, MessageType type);
std::istream& operator>>(std::istream& is, MessageType& type);


} // namespace messaging
