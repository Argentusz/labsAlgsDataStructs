#include <iostream>
#include "BitArrSet.h"

BitArrSet::BitArrSet(char name_, const std::string &str) : name(name_), array(new int[26]) {
    for(char * ptr = const_cast<char*>(str.c_str()); *ptr != '\0' && *ptr != '\n'; ptr++) {
        int index = *ptr - 'a';
        this->array[index] = 1;
    }
}

void BitArrSet::Show() {
    std::cout << this->name << " = [";
    char symb = 'a';
    for (int i=0; i<Nmax;i++){
        if(this->array[i]) {
            std::cout<<symb;
        }
        symb++;
    }
    std::cout << "]\n";
}

void BitArrSet::SetName(char n) {
    this->name = n;
}

BitArrSet &BitArrSet::operator+(BitArrSet second) {
    auto *res = new BitArrSet('\0', "");
    int i;
    for (i=0; i<Nmax; i++){
        if (this->array[i]||second.array[i]) {
            res->array[i] = 1;
        } else {
            res->array[i] = 0;
        }
    }
    return *res;
}

BitArrSet &BitArrSet::operator=(const BitArrSet & B) {
    if (this != &B) {
        this->array = B.array;
        this->name = B.name;
    }
    return *this;
}

BitArrSet &BitArrSet::operator-(BitArrSet& second) {
    auto *res = new BitArrSet('\0', "");
    int i;
    for (i=0; i<Nmax; i++){
        if (!this->array[i] || (this->array[i]+second.array[i]==2)) {
            res->array[i] = 0;
        } else {
            res->array[i] = 1;
        }
    }
    return *res;
}
