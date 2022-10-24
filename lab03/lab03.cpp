#include "Tree.h"
#include "random"
#include <iostream>

int main() {
    std::string temp{};
    Tree Tr{'a', 'z', 7};
    setlocale(LC_ALL, "Russian");
    Tr.MakeTree();
    if (Tr.exist()) {
        Tr.OutTree();
        std::cout << '\n' << "Обход в глубину: ";
        temp = Tr.DFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
        std::cout << '\n' << "Обход в ширину: ";
        temp = Tr.BFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
    } else std::cout << "Дерево пусто!";
}