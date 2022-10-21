#include <string>

class MachineWordSet {
private:
    unsigned int num;
    char name;
public:
    MachineWordSet(char, const std::string&);
    void Show();
    MachineWordSet& operator + (MachineWordSet) const;
    MachineWordSet& operator = (MachineWordSet);
    MachineWordSet& operator - (MachineWordSet);
    void SetName(char name);
};
