#ifndef ZADAN3_H
#define ZADAN3_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Класс реализует функционал неупорядоченного множества с уникальными элементами
class UnorderedSet {
private:
    set<string> elements; // Хранение уникальных элементов

public:
    // Добавление элемента в коллекцию
    void add(const string& value);

    // Удаление элемента из коллекции
    void remove(const string& value);

    // Объединение двух коллекций
    UnorderedSet Union(const UnorderedSet& other) const;

    // Разность двух коллекций
    UnorderedSet Except(const UnorderedSet& other) const;

    // Пересечение двух коллекций
    UnorderedSet Intersect(const UnorderedSet& other) const;

    // Проверка наличия элемента
    bool Contains(const string& value) const;

    // Получение всех элементов в виде вектора
    vector<string> getElements() const;

    // Вывод множества
    void print() const;
};

#endif // LAB6_H
