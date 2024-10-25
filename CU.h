#ifndef CU_H
#define CU_H

#include "Register.h"
#include "Memory.h"
#include "ALU.h"

class CU {
public:
    void load(int idxReg, int intMem, Register& reg, Memory& mem);
    void load(int idxReg, std::string val, Register& reg);
    void store(int idxReg, int idxMem, Register& reg, Memory& mem);
    void move(int idx1Reg, int idx2Reg, Register& reg);
    void jump(int idxReg, int idxMem, Register& reg, int& PC);
    void halt() const;
};

#endif
