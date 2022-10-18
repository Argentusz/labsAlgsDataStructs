#include <cstring>
#include <iostream>

class Set {
private: // Закрытая часть класса — данные
    static int N; // мощность универсума
    int n; // мощность множества
    char S, *A; // тег и память для множества
public: // Открытая часть — функции для работы с множеством
    Set& operator | (const Set&) const; // объединение
    Set& operator & (const Set&) const; // пересечение
    Set& operator ~ ( ) const; // дополнение до универсума
    void Show( ); // вывод множества на экран
    int power( ); // получение мощности
    Set(char); // конструктор множества
    Set( ); // ещё конструктор — по умолчанию
    Set(const Set &); // конструктор копии
    Set& operator = (const Set &); // оператор присваивания
    ~Set( ); // деструктор
};