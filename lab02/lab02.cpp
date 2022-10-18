#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Set.h"
using namespace std;
int Set::N = 26; // определение статического члена класса
int main()
{ srand(time(nullptr));
    class Set A('A'), B('B'), C('C'), D('D'), E;
    E = A&~(B|C|D);
    E.Show();
    return 0;
}