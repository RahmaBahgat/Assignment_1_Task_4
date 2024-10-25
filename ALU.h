#ifndef ALU_H
#define ALU_H

#include <string>

class Register;

class ALU {
public:
    std::string hexToDec(const std::string& hex);
    std::string decToHex(int dec);
    bool isValid(const std::string& value);
    void add(int idx1, int idx2, int resultIdx, Register& reg);
};

#endif
