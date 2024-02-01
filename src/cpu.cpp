// cpu.cpp
#include "cpu.h"

CPU::CPU() {
    init();
}

void CPU::init() {
    // Initialize CPU registers and flags
    a = 0;
    x = 0;
    y = 0;
    status = 0;
    pc = 0;
}

void CPU::executeCycle() {
    // Fetch the opcode from memory
    uint8_t opcode = memory[pc];
    pc++; // Increment the program counter

    // Handle different opcodes
    switch (opcode) {
        case 0x00: // NOP (No Operation)
            break;
        // Add more opcodes here
        default:
            // Handle illegal opcodes
            break;
    }
}
