#ifndef ZADAN4_H
#define ZADAN4_H
#include <string>
#include <unordered_set>
#include <iostream>

class Unordered {
private:
    std::unordered_set<std::string> elements; // Хранит уникальные элементы

public:
    // Добавляет элемент в коллекцию
    void add(const std::string& element);

    // Удаляет элемент из коллекции
    void remove(const std::string& element);

    // Объединяет текущую коллекцию с другой
    Unordered Union(const Unordered& other) const;

    // Удаляет из текущей коллекции элементы другой коллекции
    Unordered Except(const Unordered& other) const;

    // Возвращает пересечение текущей коллекции и другой
    Unordered Intersect(const Unordered& other) const;

    // Проверяет, содержит ли коллекция заданный элемент
    bool Contains(const std::string& element) const;

    // Выводит все элементы коллекции
    void print() const;

    // Возвращает количество элементов
    size_t size() const;
};

// Функция для поиска символов, встречающихся в одном и только в одном слове
void findUniqueSymbols(const std::string& text);

#endif
