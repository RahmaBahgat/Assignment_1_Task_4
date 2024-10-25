#ifndef MAINUI_H
#define MAINUI_H

#include "Machine.h"
#include <vector>
#include <string>

class MainUI {
private:
    Machine machine;

public:
    void displayMenu();
    std::vector<std::string> inputProgram();
    void run();
};

#endif
