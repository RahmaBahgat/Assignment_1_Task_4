#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include <vector>

class Register {
private:
    std::vector<std::string> registers;

public:
    Register();
    std::string getCell(int idx) const;
    void setCell(int idx, const std::string& value);
};

#endif
