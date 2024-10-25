#include "MainUI.h"
#include <iostream>

void MainUI::displayMenu() {
    std::cout << "1. Load program\n";
    std::cout << "2. Run program\n";
    std::cout << "3. Display machine state\n";
    std::cout << "4. Exit\n";
}

std::vector<std::string> MainUI::inputProgram() {
    std::vector<std::string> program;
    std::string line;
    std::cout << "Enter program lines (type 'end' to finish): \n";
    while (std::getline(std::cin, line) && line != "end") {
        program.push_back(line);
    }
    return program;
}

void MainUI::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                machine.loadProgram(inputProgram());
                break;
            case 2:
                machine.run();
                break;
            case 3:
                machine.displayState();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    } while (choice != 4);
}
