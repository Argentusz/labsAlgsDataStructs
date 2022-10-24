#include "Node.h"



class Tree {
    int rowLen = 100;
    int Nmax = 26;
    Node * root;
    char startName, endName;		//счётчик тегов и максимальный тег
    int maxRowAmount, offset;		//максимальная глубина, смещение корня
    char ** SCREEN;	// память для выдачи на экран
    void clrScr();	// очистка рабочей памяти
    Node* MakeNode(int depth);	// создание поддерева
    void OutNodes(Node * v, int r, int c); // выдача поддерева
    Tree (const Tree &);	// фиктивный конструктор копии
public:
    Tree(char num, char maxNum, int maxRow);
    ~Tree();
    Tree operator = (const Tree &) const = delete;	// присваивание
    void MakeTree() {
        root = MakeNode(0);
    }
    bool exist() {
        return root != nullptr;
    } // проверка «дерево не пусто»
    std::string DFS();	// обход дерева «в глубину»
    std::string BFS();	// обход «в ширину»
    void OutTree();	// выдача на экран
};