// cpu.h
#pragma once

#include <cstdint>

class CPU {
public:
    CPU();
    void init();
    void executeCycle();

private:
    // Define CPU registers and flags here
    uint8_t a;      // Accumulator register
    uint8_t x;      // X register
    uint8_t y;      // Y register
    uint8_t status; // Status register (flags)
    uint16_t pc;     // Program counter
};
