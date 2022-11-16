#include "Tree.h"
#include "random"
#include <iostream>

int mainLab03() {
    std::string temp{};
    setlocale(LC_ALL, "Russian");
    Tree Tr{'a', 'f', 5, 80};
    Tr.MakeTree();
    if (Tr.exist()) {
        Tr.OutTree();
        Tr.OutTree2();
        std::cout << '\n' << "Обход в глубину: ";
        temp = Tr.DFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
        std::cout << '\n' << "Обход в ширину: ";
        temp = Tr.BFS();
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
        std::cout << '\n' << "Внутренний обход: ";
        temp = Tr.IS(Tr.Root());
        std::cout << temp << " Пройдено узлов = " << temp.size()/2;
    } else std::cout << "Дерево пусто!";
}