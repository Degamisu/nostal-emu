// ppu.h
#ifndef PPU_H
#define PPU_H

#include <vector>
#include "memory.h"

class PPU {
public:
    PPU();
    ~PPU();
    void renderFrame();
    uint8_t readMemory(uint16_t address);
    void writeMemory(uint16_t address, uint8_t data);
private:
    // PPU registers
    uint8_t control;
    uint8_t mask;
    uint8_t status;
    uint16_t oamAddress;
    uint8_t scroll;
    uint8_t ppuAddress;
    uint8_t ppuData;

    // PPU memory
    std::vector<uint8_t> vram;
    std::vector<uint8_t> oam;

    // Internal variables
    uint16_t fineY;
    uint16_t targetCycle;
    uint16_t cycle;
    uint16_t scanline;
    bool rendering;

    void fetchBackgroundPixel();
    void fetchSpritePixel();
    void handleSprites();
    void handleBackground();
    void handleRendering();
};

#endif // PPU_H