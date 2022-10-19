#include <iostream>
#include "ListSet.h"
#include "helpers.h"

ListSet *ListSet::ListAppends(ListSet *setTail, char letter) {
    auto *ptr = static_cast<ListSet *>(malloc(sizeof(ListSet)));
    if (setTail->letter == -1) {
        ptr = setTail;
        ptr->prev = nullptr;
    } else {
        ptr->letter = '\0';
        setTail->next = ptr;
        ptr->prev = setTail;
    }
    ptr->next = nullptr;
    ptr->letter = letter;
    setTail = ptr;
    return setTail;
}



ListSet& ListSet :: operator-(ListSet what) {
    ListSet from_('\0', this->string());
    ListSet * from = &from_;
    for(ListSet * fromPtr = from; fromPtr != nullptr; fromPtr = fromPtr->next) {
        bool isIn = false;
        for(ListSet * whatPtr = &what; whatPtr != nullptr; whatPtr = whatPtr->next) {
            if (whatPtr->letter == fromPtr->letter) {
                isIn = true;
                break;
            }
        }
        if(isIn) {
            if(fromPtr->next != nullptr && fromPtr->prev != nullptr) {
                fromPtr->prev->next = fromPtr->next;
                fromPtr->next->prev = fromPtr->prev;
            } else if (fromPtr->next == nullptr && fromPtr->prev == nullptr) {
                fromPtr = nullptr;
            } else if (fromPtr->next == nullptr) {
                fromPtr->prev->next = nullptr;
            } else {
                fromPtr->next->prev = nullptr;
                from = from->next;
            }
        }
        if(fromPtr == nullptr) break;
    }
    return *from;
}

void ListSet :: operator + (ListSet B) {
    ListSet * destTail;
    for(destTail = this; destTail->next != nullptr; destTail = destTail->next);
    for(ListSet * srcPtr = &B; srcPtr != nullptr; srcPtr = srcPtr->next) {
        bool isIn = false;
        for(ListSet * destPtr = this; destPtr != nullptr; destPtr = destPtr->next) {
            if (destPtr->letter == srcPtr->letter) {
                isIn = true;
                break;
            }
        }
        if (!isIn) {
            destTail = ListAppends(destTail, srcPtr->letter);
        }
    }
}

ListSet::ListSet(char name, const std::string& tempLine) : name(name), prev(nullptr), letter(-1), next(nullptr) {
        ListSet * setTail = this;
        for(char * ptr = const_cast<char*>(tempLine.c_str()); *ptr != '\0'; ptr++) {
            setTail = ListAppends(setTail, *ptr);
        }
}

void ListSet::Show() {
    ListSet * ptr;
    std::cout << this->name << " = [";
    for(ptr = this; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->letter;
    }
    std::cout << "]\n";
}

std::string ListSet::string() {
    auto res = *new std::string ;
    for(ListSet * ptr = this; ptr != nullptr; ptr = ptr->next) {
        res += ptr->letter;
    }
    return res;
}

void ListSet::SetName(char n) {
    this->name = n;
}

ListSet &ListSet::operator = (const ListSet & B) = default;
