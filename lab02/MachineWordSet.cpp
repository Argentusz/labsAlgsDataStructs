#include <iostream>
#include "MachineWordSet.h"

MachineWordSet::MachineWordSet(char n, const std::string &tempLine) : name(n), num(0) {
    for(char * ptr = const_cast<char*>(tempLine.c_str()); *ptr != '\0' && *ptr != '\n'; ptr++) {
        unsigned number = 1 << (*ptr - 'a');
        this->num = this->num | number;
    }
}

void MachineWordSet::Show() {
    auto temp = this->num;
    std::cout << this->name << " = [";
    for(char ltr = 'a'; ltr <= 'z'; ltr++) {
        if(temp%2) std::cout << ltr;
        temp = temp >> 1;
    }
    std::cout << "]\n";
}

void MachineWordSet::SetName(char n) {
    this->name = n;
}

MachineWordSet &MachineWordSet::operator+(MachineWordSet B) const {
    auto *res = new MachineWordSet('\0', "");
    res->num = this->num | B.num;
    return *res;
}

MachineWordSet &MachineWordSet::operator=(MachineWordSet B) {
    this->num = B.num;
    this->name = B.name;
    return *this;
}

MachineWordSet &MachineWordSet::operator-(MachineWordSet B) {
    auto *res = new MachineWordSet('\0', "");
    res->num = this->num&~(B.num);
    return *res;
}

