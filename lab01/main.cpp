#include <iostream>
#include <ctime>
#include <cstring>
#include "../lab02/helpers.h"
const int Nmax = 26;
int mainLab01() {
    int choose;
    char ** str;
    std::cout << "1 - Array\n2 - List\n3 - Bits Array\n4 - Machine Word\n5 - Benchmark\n";
    std::cin >> choose;
    getchar();
    switch (choose) {
        case 1:
            std::cout << "Array:\n";
            asArray(nullptr);
            break;
        case 2:
            std::cout << "List:\n";
            asList(nullptr);
            break;
        case 3:
            std::cout<<"Bits Array:\n";
            asBits(nullptr);
            break;
        case 4:
            std::cout << "Machine Word:\n";
            asMachineWord(nullptr);
            break;
        case 5:
            str = new char*[4];
            for(int i = 0; i < 4; i++) {
                std::cout << "Enter " << (char)('A' + i) << ": ";
                str[i] = new char[Nmax];
                fgets(str[i], Nmax, stdin);
                if (str[i][strlen(str[i]) - 1] == '\n') {
                    str[i][strlen(str[i]) - 1] = '\0';
                }
            }
            std::cout << std::endl;
            std::cout << "Array Solution:\n";
            asArray(str);
            std::cout << std::endl;
            std::cout << "List Solution:\n";
            asList(str);
            std::cout << std::endl;
            std::cout << "Bit Array Solution:\n";
            asBits(str);
            std::cout << std::endl;
            std::cout << "Machine Word Solution:\n";
            asMachineWord(str);
            break;
        default:;
    }
    return 0;
}

