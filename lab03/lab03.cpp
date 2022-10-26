#include "Tree.h"
#include "random"
#include <iostream>

int main() {
    std::string temp{};
    Tree Tr{'a', 'z'};
    Tree Tr2{'!', 'z', 10, 300};

    setlocale(LC_ALL, "Russian");
    Tr.MakeTree();
    Tr2.MakeTree();
    if (Tr.exist()) {
        Tr.OutTree();
        std::cout << '\n' << "Обход в глубину: ";
        temp = Tr.DFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
        std::cout << '\n' << "Обход в ширину: ";
        temp = Tr.BFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2 << "\n";
    } else std::cout << "Дерево пусто!";
    if (Tr2.exist()) {
        Tr2.OutTree();
        temp = Tr2.DFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
        std::cout << '\n' << "Обход в ширину: ";
        temp = Tr2.BFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2 << "\n";
    }
}