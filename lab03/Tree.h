#include "Node.h"

class Tree {
    Node * root;	// указатель на корень дерева
    char num, maxnum;		//счётчик тегов и максимальный тег
    int maxrow, offset;		//максимальная глубина, смещение корня
    char ** SCREEN;	// память для выдачи на экран
    void clrscr();	// очистка рабочей памяти
    Node* MakeNode(int depth);	// создание поддерева
    void OutNodes(Node * v, int r, int c); // выдача поддерева
    Tree (const Tree &);	// фиктивный конструктор копии
    Tree (Tree &&);		//копия с переносом (С++11)
    Tree operator = (const Tree &) const = delete;	// присваивание
    Tree operator = (Tree &&) const = delete; // то же,  с переносом
public:
    Tree(char num, char maxnum, int maxrow);
    ~Tree();
    void MakeTree() // ввод — генерация дерева
    { root = MakeNode(0); }
    bool exist() { return root != nullptr; } // проверка «дерево не пусто»
    int DFS();	// обход дерева «в глубину»
    int BFS();	// обход «в ширину»
    void OutTree();	// выдача на экран
};