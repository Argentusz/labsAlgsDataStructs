#include <string>

class BitArrSet {
private:
    int * array;
    char name;
    const int Nmax = 26;
public:
    BitArrSet(char, const std::string&);
    void Show();
    void SetName(char);
    BitArrSet& operator + (BitArrSet);
    BitArrSet& operator - (BitArrSet&);
    BitArrSet& operator = (const BitArrSet&);
};
