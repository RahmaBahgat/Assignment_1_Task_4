#include "CU.h"
#include <iostream>

void CU::load(int idxReg, int intMem, Register& reg, Memory& mem) {
    reg.setCell(idxReg, mem.getCell(intMem));
}

void CU::load(int idxReg, std::string val, Register& reg) {
    reg.setCell(idxReg, val);
}

void CU::store(int idxReg, int idxMem, Register& reg, Memory& mem) {
    if (idxMem == 0) {
        storeToScreen(idxReg, reg, mem);
    } else {
        mem.setCell(idxMem, reg.getCell(idxReg));
    }
}

void CU::storeToScreen(int idxReg, Register& reg, Memory& mem) {
    // Display the contents of the register to the screen (assuming some display functionality).
    std::cout << "Screen Output: " << reg.getCell(idxReg) << std::endl;
}

void CU::move(int idx1Reg, int idx2Reg, Register& reg) {
    reg.setCell(idx2Reg, reg.getCell(idx1Reg));
}

void CU::addTwosComplement(int idxRegR, int idxRegS, int idxRegT, Register& reg, ALU& alu) {
    // Adds two's complement values in registers S and T, places result in register R.
    int sum = alu.addTwosComplement(reg.getCell(idxRegS), reg.getCell(idxRegT));
    reg.setCell(idxRegR, sum);
}

void CU::addFloatingPoint(int idxRegR, int idxRegS, int idxRegT, Register& reg, ALU& alu) {
    // Adds floating-point values in registers S and T, places result in register R.
    float sum = alu.addFloatingPoint(reg.getCell(idxRegS), reg.getCell(idxRegT));
    reg.setCell(idxRegR, sum);
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
