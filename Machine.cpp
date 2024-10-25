#include "Machine.h"

Machine::Machine() {}

void Machine::loadProgram(const std::vector<std::string>& program) {
    cpu.loadProgram(program, memory);
}

void Machine::run() {
    while (true) {
        cpu.fetch(memory);
        cpu.decodeAndExecute(memory);
    }
}

void Machine::displayState() const {
    cpu.showState(memory);
}
