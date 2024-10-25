#include "Memory.h"

Memory::Memory() : memory(256, "0000") {}  // Initialize 256 memory cells to "0000"

std::string Memory::getCell(int address) const {
    return memory[address];
}

void Memory::setCell(int address, const std::string& value) {
    memory[address] = value;
}
