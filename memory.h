#ifndef MEMORY_H
#define MEMORY_H

#include <string>
#include <vector>

class Memory {
private:
    std::vector<std::string> memory;

public:
    Memory();
    std::string getCell(int address) const;
    void setCell(int address, const std::string& value);
};

#endif
