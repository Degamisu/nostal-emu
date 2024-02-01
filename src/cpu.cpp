#include "cpu.h"

CPU::CPU() {
    init();
}

void CPU::init() {
    // Initialize CPU registers and flags
    a = 0;
    x = 0;
    y = 0;
    sp = 0xFD;
    status = 0;
    pc = 0;
}

void CPU::executeCycle() {
    // Fetch the opcode from memory
    opcode = memory[pc];
    pc++; // Increment the program counter

    // Handle different opcodes
    switch (opcode) {
        case NOP: // NOP (No Operation)
            break;
        case LDA: // LDA (Load Accumulator)
            a = memory[pc];
            pc++;
            break;
        case STA: // STA (Store Accumulator)
            memory[pc - 1] = a;
            break;
        case BRK: // BRK (Break)
            // Implement the BRK instruction, including pushing the program counter and status onto the stack
            // and setting the Break flag
            memory[sp--] = pc & 0xFF; // Push LSB of PC onto the stack
            memory[sp--] = (pc >> 8) & 0xFF; // Push MSB of PC onto the stack
            memory[sp--] = status | 0x01; // Push status with Break flag set onto the stack
            status |= 0x01; // Set the Break flag
            pc = memory.at(0xFFFE) | (memory.at(0xFFFF) << 8); // Jump to the reset vector
            break;
        case JMP: // JMP (Jump)
            // Implement the jmp by jumping to the address in the following two bytes
            address = memory[pc] | (memory[pc + 1] << 8);
            pc += 2;
            pc = address;
            break;
        case JSR: // JSR (Jump to Suboutine)
            // Implement the jsr by pushing the return onto the stack and then jumping to the
            address = memory[pc++] | (memory[pc++] << 8);
            memory[sp--] = (pc + 1) & 0xFF; // Push LSB of return address onto the stack
            memory[sp--] = ((pc + 1) >> 8) & 0xFF; // Push MSB of return address onto the stack
            pc = address;
            break;

            
        default:
            // Handle illegal opcodes
            break;
    }
}