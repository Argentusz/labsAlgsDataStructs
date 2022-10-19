#include <cstring>
#include <iostream>

class ArraySet {
private: // Закрытая часть класса — данные
    static int N; // мощность универсума
    int n; // мощность множества
    char S, *A; // тег и память для множества
public: // Открытая часть — функции для работы с множеством
    ArraySet& operator | (const ArraySet&) const; // объединение
    ArraySet& operator & (const ArraySet&) const; // пересечение
    ArraySet& operator ~ ( ) const; // дополнение до универсума
    void Show( ); // вывод множества на экран
    int power( ) const; // получение мощности
    ArraySet(char, const std::string&); // конструктор множества
    ArraySet( ); // ещё конструктор — по умолчанию
    ArraySet(const ArraySet &); // конструктор копии
    ArraySet& operator = (const ArraySet &); // оператор присваивания
    ~ArraySet( ); // деструктор
};