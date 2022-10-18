#include <string>

class ListSet {
private:
    signed char letter;
    ListSet * next;
    ListSet * prev;
    char name;
    static ListSet * ListAppends(ListSet * setTail, char letter);
public:
    ListSet(char, const std::string&);
    void Show();
    std::string string();
    void SetName(char);
    void operator + (ListSet);
    ListSet& operator - (ListSet);
    ListSet& operator = (const ListSet&);
};
