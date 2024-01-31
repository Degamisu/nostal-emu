# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(nes-emulator C)

set(CMAKE_C_STANDARD 11)

# Include GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_executable(nes-emulator src/main.c src/cpu.c)
target_link_libraries(nes-emulator ${GTK3_LIBRARIES})
include_directories(${GTK3_INCLUDE_DIRS})
target_include_directories(nes-emulator PUBLIC include)  # Add this line