#include "ALU.h"
#include "Register.h"
#include <sstream>
#include <iomanip>
#include <iostream>

std::string ALU::hexToDec(const std::string& hex) {
    int dec;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> dec;
    return std::to_string(dec);
}

std::string ALU::decToHex(int dec) {
    std::stringstream ss;
    ss << std::hex << std::setw(4) << std::setfill('0') << dec;
    return ss.str();
}

bool ALU::isValid(const std::string& value) {
    return value.size() == 4;
}

void ALU::add(int idx1, int idx2, int resultIdx, Register& reg) {
    int val1 = std::stoi(hexToDec(reg.getCell(idx1)));
    int val2 = std::stoi(hexToDec(reg.getCell(idx2)));
    int result = val1 + val2;
    reg.setCell(resultIdx, decToHex(result));
}
