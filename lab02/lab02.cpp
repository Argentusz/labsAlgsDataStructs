#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Set.h"
using namespace std;
int Set::N = 26; // определение статического члена класса
const long q0 = 100000; // количество повторений цикла времени
int main()
{ srand(time(nullptr));
    class Set A('A'), B('B'), C('C'), D('D'), E;
    for(long q =0; q < q0; q++)
    { E = (A | B) & (C & ~D); }
    cout << " Middle power =" <<
         (A.power() + B.power() + C.power() + D.power() + E.power()) / 5
         << q0 << endl;
    return 0;
}