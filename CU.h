#ifndef CU_H
#define CU_H

#include "Register.h"
#include "Memory.h"
#include "ALU.h"
#include <string>

class CU {
public:
    void load(int idxReg, int intMem, Register& reg, Memory& mem);         // RXY
    void load(int idxReg, std::string val, Register& reg);                 // RXY (register with bit pattern)
    void store(int idxReg, int idxMem, Register& reg, Memory& mem);        // RXY (store)
    void move(int idx1Reg, int idx2Reg, Register& reg);                    // 0RS
    void jump(int idxReg, int idxMem, Register& reg, int& PC);             // BXY
    void halt() const;                                                     // C000
};

#endif
