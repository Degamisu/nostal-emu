// cpu.h
#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    // Define CPU registers and flags here
    uint8_t a;      // Accumulator register
    uint8_t x;      // X register
    uint8_t y;      // Y register
    uint8_t status; // Status register (flags)
    uint16_t pc;     // Program counter
} CPU;

// Function to initialize the CPU
void init_cpu(CPU *cpu);

// Function to execute one CPU cycle
void execute_cpu_cycle(CPU *cpu);

#endif