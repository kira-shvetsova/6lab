#ifndef LAB6_H
#define LAB6_H

// Класс, представляющий узел однонаправленного списка
class Node {
public:
    int data;        // Данные, хранящиеся в узле
    Node* next;     // Указатель на следующий узел

    // Конструктор для инициализации узла
    Node(int value) : data(value), next(nullptr) {}
};

// Класс, представляющий однонаправленный список
class LinkedList {
private:
    Node* head;     // Указатель на голову списка

public:
    LinkedList();   // Конструктор
    ~LinkedList();  // Деструктор

    void add(int data);            // Метод для добавления элемента в список
    void remove(int data);         // Метод для удаления элемента из списка
    void repeatElements(int element); // Метод для повторения указанного элемента
    void printList() const;        // Метод для вывода списка на экран
};

#endif 
