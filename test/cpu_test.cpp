#include "gtest/gtest.h"
#include "cpu.h"
#include "memory.h"

// Helper function to create a CPU with a filled memory
CPU createCPUWithMemory(const std::vector<uint8_t>& memoryData) {
    Memory memory(memoryData);
    CPU cpu;
    cpu.setMemory(&memory);
    return cpu;
}

// Test the init method
TEST(CPUTest, Init) {
    CPU cpu;
    EXPECT_EQ(cpu.a, 0);
    EXPECT_EQ(cpu.x, 0);
    EXPECT_EQ(cpu.y, 0);
    EXPECT_EQ(cpu.sp, 0xFD);
    EXPECT_EQ(cpu.status, 0);
    EXPECT_EQ(cpu.pc, 0);
}

// Test the LDA instruction
TEST(CPUTest, LDA) {
    std::vector<uint8_t> memoryData = {
        0xA9, 0x0A, // LDA #$0A
        0x85, 0x00  // STA $00
    };
    CPU cpu = createCPUWithMemory(memoryData);
    cpu.executeCycle();
    cpu.executeCycle();

    EXPECT_EQ(cpu.a, 0x0A);
    EXPECT_EQ(cpu.memory[0x0000], 0x0A);
}

// Test the STA instruction
TEST(CPUTest, STA) {
    std::vector<uint8_t> memoryData = {
        0xA9, 0x0A, // LDA #$0A
        0x00, 0x00  // STA $0000
    };
    CPU cpu = createCPUWithMemory(memoryData);
    cpu.executeCycle();
    cpu.executeCycle();

    EXPECT_EQ(cpu.memory[0x0000], 0x0A);
}

// Test the BRK instruction
TEST(CPUTest, BRK) {
    std::vector<uint8_t> memoryData = {
        0x00, // BRK
    };
    CPU cpu = createCPUWithMemory(memoryData);

    // The reset vector points to 0x8000, so we expect the PC to be 0x8000 after BRK
    EXPECT_EQ(cpu.pc, 0x8000);
}

// Test the JMP instruction
TEST(CPUTest, JMP) {
    std::vector<uint8_t> memoryData = {
        0x4C, 0x00, 0x01, // JMP $0100
        0xEA, 0xEA, 0xEA  // NOPs
    };
    CPU cpu = createCPUWithMemory(memoryData);
    cpu.pc = 0x00F0; // Set the PC to an arbitrary value before JMP

    cpu.executeCycle();
    cpu.executeCycle();
    cpu.executeCycle();

    EXPECT_EQ(cpu.pc, 0x0100);
}

// Test the JSR instruction
TEST(CPUTest, JSR) {
    std::vector<uint8_t> memoryData = {
        0x20, 0x00, 0x01, // JSR $0100
        0xEA, 0xEA, 0xEA  // NOPs
    };
    CPU cpu = createCPUWithMemory(memoryData);
    cpu.pc = 0x00F0; // Set the PC to an arbitrary value before JSR

    cpu.executeCycle();
    cpu.executeCycle();
    cpu.executeCycle();

    // Check the return address on the stack
    EXPECT_EQ(cpu.memory[cpu.sp + 1], (cpu.pc + 1) & 0xFF);
    EXPECT_EQ(cpu.memory[cpu.sp + 2], ((cpu.pc + 1) >> 8) & 0xFF);
    EXPECT_EQ(cpu.pc, 0x0100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}