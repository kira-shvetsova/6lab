#include "lab6.h"
#include <iostream>

// Конструктор, инициализирующий голову списка нулевым указателем
LinkedList::LinkedList() : head(nullptr) {}

// Деструктор, освобождающий память, занятую узлами списка
LinkedList::~LinkedList() {
    Node* current = head; // Начинаем с головы списка
    while (current != nullptr) {
        Node* nextNode = current->next; // Сохраняем указатель на следующий узел
        delete current;                  // Освобождаем память текущего узла
        current = nextNode;              // Переходим к следующему узлу
    }
}

// Метод для добавления нового элемента в конец списка
void LinkedList::add(int data) {
    Node* newNode = new Node(data); // Создаём новый узел
    if (!head) {
        head = newNode; // Если список пуст, новый узел становится головой
        return;
    }
    Node* lastNode = head; // Иначе ищем последний узел
    while (lastNode->next) {
        lastNode = lastNode->next; // Переходим к следующему узлу
    }
    lastNode->next = newNode; // Добавляем новый узел в конец списка
}

// Метод для удаления элемента из списка
void LinkedList::remove(int data) {
    Node* current = head; // Начинаем с головы списка
    Node* previous = nullptr; // Предыдущий узел (изначально пустой)

    // Ищем элемент для удаления
    while (current != nullptr && current->data != data) {
        previous = current;       // Обновляем предыдущий узел
        current = current->next;  // Переходим к следующему узлу
    }

    if (current == nullptr) return; // Элемент не найден

    if (previous == nullptr) {
        head = current->next; // Удаляем голову списка
    }
    else {
        previous->next = current->next; // Удаляем текущий узел
    }

    delete current; // Освобождаем память удаляемого узла
}

// Метод для повторения указанного элемента в списке
void LinkedList::repeatElements(int element) {
    Node* current = head; // Начинаем с головы списка
    while (current != nullptr) {
        if (current->data == element) { // Если нашли совпадение
            Node* newNode = new Node(element); // Создаём новый узел с тем же элементом
            newNode->next = current->next; // Новый узел указывает на следующий после текущего
            current->next = newNode; // Текущий узел указывает на новый узел
            current = newNode->next; // Пропускаем новый узел и переходим к следующему
        }
        else {
            current = current->next; // Переходим к следующему узлу
        }
    }
}

// Метод для вывода элементов списка на экран
void LinkedList::printList() const {
    Node* current = head; // Начинаем с головы списка
    while (current != nullptr) {
        std::cout << current->data << " -> "; // Выводим данные текущего узла
        current = current->next; // Переходим к следующему узлу
    }
    std::cout << "nullptr" << std::endl; // Завершаем вывод указателем на ноль
}
