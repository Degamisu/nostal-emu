#ifndef CPU_H
#define CPU_H

#include <vector>

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
    uint16_t sp;
    uint16_t status;
    uint16_t pc;

    // Memory-mapped Registers
    std::vector<uint8_t> memory;

    // Instruction Set
    #define NOP 0xEA
    #define LDA 0xA9
    #define STA 0x85
    #define BRK 0x00
    #define JMP 0x4C
    #define JSR 0x20

    // Instruction Operands
    uint8_t opcode;
    uint16_t address;
};

#endif