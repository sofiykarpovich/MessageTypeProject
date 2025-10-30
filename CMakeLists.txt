cmake_minimum_required(VERSION 3.16)
project(MessageType LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(message_type src/message_type.cpp)


target_include_directories(message_type
PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)


if (MSVC)
target_compile_options(message_type PRIVATE /W4 /permissive-)
else()
target_compile_options(message_type PRIVATE -Wall -Wextra -Wpedantic)
endif()


# --- main ---
add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE message_type)


# --- GoogleTest ---
include(FetchContent)
FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)


enable_testing()
add_executable(test_message_type tests/test_message_type.cpp)
target_link_libraries(test_message_type PRIVATE message_type gtest_main)


include(GoogleTest)
gtest_discover_tests(test_message_type)
