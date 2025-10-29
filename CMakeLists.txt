cmake_minimum_required(VERSION 3.14)
project(MessageTypeProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# cereal
FetchContent_Declare(
  cereal
  GIT_REPOSITORY https://github.com/USCiLab/cereal.git
  GIT_TAG v1.3.2
)
FetchContent_MakeAvailable(cereal)

# magic_enum
FetchContent_Declare(
  magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
  GIT_TAG v0.9.3
)
FetchContent_MakeAvailable(magic_enum)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

# main 
add_executable(MessageTypeApp
    src/main.cpp
    src/MessageType.cpp
)
target_link_libraries(MessageTypeApp cereal magic_enum)

# tests
add_executable(MessageTypeTests
    tests/test_MessageType.cpp
    src/MessageType.cpp
)
target_link_libraries(MessageTypeTests PRIVATE gtest_main cereal magic_enum)

include(GoogleTest)
gtest_discover_tests(MessageTypeTests)
