#ifndef CPU_H
#define CPU_H

#include <string>
#include "Register.h"
#include "Memory.h"
#include "ALU.h"
#include "CU.h"

class CPU {
private:
    int programCounter;
    std::string instructionRegister;
    Register reg;
    ALU alu;
    CU cu;

public:
    CPU();
    void fetch(Memory& mem);
    void decodeAndExecute(Memory& mem);
    void loadProgram(const std::vector<std::string>& program, Memory& mem);
    void showState(const Memory& mem) const;
};

#endif
