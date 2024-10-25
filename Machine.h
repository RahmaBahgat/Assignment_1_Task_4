#ifndef MACHINE_H
#define MACHINE_H

#include "CPU.h"

class Machine {
private:
    CPU cpu;
    Memory memory;

public:
    Machine();
    void loadProgram(const std::vector<std::string>& program);
    void run();
    void displayState() const;
};

#endif
