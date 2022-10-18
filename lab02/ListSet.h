#include <string>

class ListSet {
private:
    signed char letter;
    ListSet * next;
    ListSet * prev;
    static ListSet * ListAppends(ListSet * setTail, char letter);
public:
    ListSet(const std::string&);
    void Show();
    std::string string();
    void operator + (ListSet);
    ListSet& operator - (ListSet);
    ListSet& operator = (const ListSet&);
};
