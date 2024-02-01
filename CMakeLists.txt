# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(nes-emulator-qt CXX)

set(CMAKE_CXX_STANDARD 11)

# Find the Qt5 package
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Add your source files
add_executable(nes-emulator-qt src/main.cpp src/cpu.cpp src/cpu.h)

# Link against Qt5
target_link_libraries(nes-emulator-qt PRIVATE Qt5::Widgets)