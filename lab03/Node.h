class Node {
    char d;	//тег узла
    Node * lft;	// левый сын
    Node  * mdl;	//— средний сын (если нужно)
    Node * rgt;	// правый сын
public:
    Node() : lft(nullptr), rgt(nullptr), mdl(nullptr) { } // конструктор узла
    ~Node(){
        if(lft) delete lft; // деструктор (уничтожает поддерево)
        if (rgt) delete rgt;
        if(mdl) delete mdl;
    }
    friend class Tree;	// дружественный класс «дерево»
} ;