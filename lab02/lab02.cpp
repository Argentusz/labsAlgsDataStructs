#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "ArraySet.h"
#include "ListSet.h"
#include "BitArrSet.h"
#include "MachineWordSet.h"
using namespace std;
int ArraySet::N = 26; // определение статического члена класса

void asArrayLab2(std::vector<std::string> strings);
void asListLab2(std::vector<std::string> strings);
void asBitArrayLab2(std::vector<std::string> strings);
void asMachineWordLab2(std::vector<std::string> strings);
int mainLab02()
{
    std::vector<std::string> strings;
    std::string str = *new string;
    cout << "Введите А:\n";
    cin >> str;
    strings.push_back(str);
    cout << "Введите B:\n";
    cin >> str;
    strings.push_back(str);
    cout << "Введите C:\n";
    cin >> str;
    strings.push_back(str);
    cout << "Введите D:\n";
    cin >> str;
    strings.push_back(str);

    std::cout << "Array Solution:\n";
    asArrayLab2(strings);
    std::cout << "\nList Solution:\n";
    asListLab2(strings);
    std::cout << "\nBit Array Solution:\n";
    asBitArrayLab2(strings);
    std::cout << "\nMachine Word Solution:\n";
    asMachineWordLab2(strings);

    return 0;
}

void asArrayLab2(std::vector<std::string> strings) {
    class ArraySet A('A', strings[0]);
    class ArraySet B('B', strings[1]);
    class ArraySet C('C', strings[2]);
    class ArraySet D('D', strings[3]);
    class ArraySet E('E', "");
    A.Show();
    B.Show();
    C.Show();
    D.Show();
    unsigned int start = clock();
    E = A&~(B|C|D);
    unsigned int end = clock();
    E.Show();
    std::cout << "Time elapsed: " << end - start << "ms\n";
}
void asListLab2(std::vector<std::string> strings) {
    class ListSet One('A', strings[0]);
    class ListSet Two('B', strings[1]);
    class ListSet Three('C', strings[2]);
    class ListSet Four('D', strings[3]);

    One.Show();
    Two.Show();
    Three.Show();
    Four.Show();

    unsigned int start = clock();
    Two + Three;
    Two + Four;
    ListSet res = One -  Two;
    unsigned int end = clock();
    res.SetName('E');
    res.Show();
    std::cout << "Time elapsed: " << end - start << "ms\n";
}
void asBitArrayLab2(std::vector<std::string> strings) {
    BitArrSet A1('A', strings[0]);
    BitArrSet A2('B', strings[1]);
    BitArrSet A3('C', strings[2]);
    BitArrSet A4('D', strings[3]);
    A1.Show();
    A2.Show();
    A3.Show();
    A4.Show();
    unsigned int start = clock();
    auto res2 = A1 - (A2 + A3 + A4);
    unsigned int end = clock();
    res2.SetName('E');
    res2.Show();
    std::cout << "Time elapsed: " << end - start << "ms\n";
}

void asMachineWordLab2(std::vector<std::string> strings) {
    MachineWordSet A('A', strings[0]);
    MachineWordSet B('B', strings[1]);
    MachineWordSet C('C', strings[2]);
    MachineWordSet D('D', strings[3]);
    A.Show();
    B.Show();
    C.Show();
    D.Show();
    unsigned int start = clock();
    auto E = A - (B+C+D);
    unsigned int end = clock();
    E.SetName('E');
    E.Show();
    std::cout << "Time elapsed: " << end - start << "ms\n";
}