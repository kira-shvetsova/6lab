#ifndef ZADAN2_H
#define ZADAN2_H

#include <iostream>
using namespace std;

// Структура для узла двунаправленного списка
struct Node2 {
    int data;// Данные, хранящиеся в узле
    Node2* prev;// Указатель на предыдущий узел
    Node2* next;//Указатель на следующий узел

    // Конструктор для инициализации узла с заданным значением
    Node2(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Класс двунаправленного списка
class DoublyLinkedList {
private:
    Node2* head;//Первый узел
    Node2* tail;//Последний узел

    // Метод для поиска минимального элемента
    Node2* findMin();

    // Метод для поиска максимального элемента
    Node2* findMax();

public:
    // Конструктор
    DoublyLinkedList();

    // Деструктор
    ~DoublyLinkedList();

    // Метод для добавления элемента в конец списка
    void addElement(int value);

    // Метод для вывода списка
    void printList() const;

    // Метод для замены элементов местами
    void swapSegments();

    // Метод для удаления элемента из списка
    void removeElement(int value);
};

#endif
