#include "CU.h"
#include <iostream>

void CU::load(int idxReg, int intMem, Register& reg, Memory& mem) {
    reg.setCell(idxReg, mem.getCell(intMem));
}

void CU::load(int idxReg, std::string val, Register& reg) {
    reg.setCell(idxReg, val);
}

void CU::store(int idxReg, int idxMem, Register& reg, Memory& mem) {
    mem.setCell(idxMem, reg.getCell(idxReg));
}

void CU::move(int idx1Reg, int idx2Reg, Register& reg) {
    reg.setCell(idx2Reg, reg.getCell(idx1Reg));
}

void CU::jump(int idxReg, int idxMem, Register& reg, int& PC) {
    if (reg.getCell(idxReg) == reg.getCell(0)) {
        PC = idxMem;
    }
}

void CU::halt() const {
    std::cout << "Program halted." << std::endl;
    exit(0);
}
