#include "Register.h"

Register::Register() : registers(16, "0000") {}  // Initialize 16 registers to "0000"

std::string Register::getCell(int idx) const {
    return registers[idx];
}

void Register::setCell(int idx, const std::string& value) {
    registers[idx] = value;
}
