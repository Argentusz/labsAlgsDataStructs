#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "ArraySet.h"
#include "ListSet.h"
#include "BitArrSet.h"
using namespace std;
int ArraySet::N = 26; // определение статического члена класса
int main()
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
    class ArraySet A('A', strings[0]);
    class ArraySet B('B', strings[1]);
    class ArraySet C('C', strings[2]);
    class ArraySet D('D', strings[3]);
    class ArraySet E('E', "");
    A.Show();
    B.Show();
    C.Show();
    D.Show();
    E = A&~(B|C|D);
    E.Show();
    std::cout << "\nList Solution:\n";

    class ListSet One('A', strings[0]);
    class ListSet Two('B', strings[1]);
    class ListSet Three('C', strings[2]);
    class ListSet Four('D', strings[3]);

    One.Show();
    Two.Show();
    Three.Show();
    Four.Show();

    Two + Three;
    Two + Four;
    ListSet res = One -  Two;
    res.SetName('E');
    res.Show();

    std::cout << "\nBit Array Solution:\n";
    BitArrSet A1('A', strings[0]);
    BitArrSet A2('B', strings[1]);
    BitArrSet A3('C', strings[2]);
    BitArrSet A4('D', strings[3]);
    A1.Show();
    A2.Show();
    A3.Show();
    A4.Show();
    auto res2 = A1 - (A2 + A3 + A4);
    res2.SetName('E');
    res2.Show();

    return 0;
}