#include "Tree.h"
#include "time.h"
#include "random"
#include <iostream>

int main( )
{ int n = 0;
    Tree Tr('a', 'z', 8);
    srand(time(nullptr));
    setlocale(LC_ALL, "Russian");
    Tr.MakeTree( );
    if(Tr.exist( )) {
        Tr.OutTree( );
        std::cout << '\n' << "Обход в глубину: ";
        n = Tr.DFS( );
        std::cout << " Пройдено узлов = " << n;
        std::cout << '\n' << "Обхофункциид в ширину: ";
        n = Tr.BFS( );
        std::cout << " Пройдено узлов = " << n;
    }
    else std::cout << "Дерево пусто!";
    std::cout << '\n' << "=== Конец ===";
    std::cin.get( );
}