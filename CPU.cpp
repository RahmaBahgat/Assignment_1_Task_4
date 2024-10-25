#include "CPU.h"
#include <iostream>

CPU::CPU() : programCounter(0), instructionRegister("0000") {}

void CPU::fetch(Memory& mem) {
    instructionRegister = mem.getCell(programCounter);
    programCounter++;
}

void CPU::decodeAndExecute(Memory& mem) {
    std::string opcode = instructionRegister.substr(0, 1);
    int regIndex = stoi(instructionRegister.substr(1, 1), nullptr, 16);
    int operand = stoi(instructionRegister.substr(2, 2), nullptr, 16);

    if (opcode == "1") {
        // LOAD register R with memory content
        cu.load(regIndex, operand, reg, mem);
    } else if (opcode == "2") {
        // LOAD register R with value XY
        cu.load(regIndex, instructionRegister.substr(2, 2), reg);
    } else if (opcode == "3") {
        // STORE register R to memory at address XY
        cu.store(regIndex, operand, reg, mem);
    } else if (opcode == "4") {
        // MOVE content of register R to register S
        int destReg = operand;
        cu.move(regIndex, destReg, reg);
    } else if (opcode == "5") {
        // ADD contents of two registers
        int regS = operand / 16;
        int regT = operand % 16;
        alu.add(regS, regT, regIndex, reg);
    } else if (opcode == "B") {
        // JUMP to address if register R == register 0
        cu.jump(regIndex, operand, reg, programCounter);
    } else if (opcode == "C") {
        // HALT the program
        cu.halt();
    }
}

void CPU::loadProgram(const std::vector<std::string>& program, Memory& mem) {
    for (int i = 0; i < program.size(); ++i) {
        mem.setCell(i, program[i]);
    }
}

void CPU::showState(const Memory& mem) const {
    std::cout << "Program Counter: " << programCounter << "\n";
    std::cout << "Instruction Register: " << instructionRegister << "\n";
    std::cout << "Memory[0]: " << mem.getCell(0) << "\n";
    std::cout << "Register[0]: " << reg.getCell(0) << "\n";
}
