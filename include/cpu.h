#ifndef CPU_H
#define CPU_H

#include <cstdint>

class CPU {
public:
    CPU();
    void init();
    void executeCycle();

private:
    // CPU Registers and Flags
    uint8_t a;
    uint8_t x;
    uint8_t y;
    unsigned short sp;
    unsigned short status;
    unsigned short pc;

    // Memory-mapped Registers
    unsigned char memory[0x10000];

    // Instruction Set
    constexpr unsigned char NOP = 0xEA;
    constexpr unsigned char LDA = 0xA9;
    constexpr unsigned char STA = ``````  0x85;
    constexpr unsigned char BRK = 0x00;
    constexpr unsigned char JMP = 0xC;
    constexpr unsigned char JSR = 0x0;

    // Instruction Operands
    unsigned char opcode;
    unsigned short address;
};

#endif