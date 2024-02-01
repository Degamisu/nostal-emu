// cpu.h
#ifndef CPU_H
#include <array>

//define the uint8_t and uint16_t identifiers
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

class CPU {
private:
    std::array<uint8_t, 0x10000> memory;
    uint8_t a, x, y, sp;
    uint16_t pc;
    uint8_t status;

public:
    CPU();
    void init();
    void executeCycle();
};

#endif // CPU_H