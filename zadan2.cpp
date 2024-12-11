#include "zadan2.h"
#include <iostream>

// Конструктор
DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

// Деструктор
DoublyLinkedList::~DoublyLinkedList() {
    Node2* current = head; //Начинаем с головы списка
    while (current) {
        Node2* toDelete = current; // Запоминаем узел для удаления
        current = current->next;//Переходим к следующему узлу
        delete toDelete; //Удаляем текущий
    }
}

// Метод добавления элемента в конец списка
void DoublyLinkedList::addElement(int value) {
    Node2* newNode = new Node2(value);// Создаем новый узел с заданным значением
    if (!head) {
        head = tail = newNode;// Если список пуст, новый узел становится головой и хвостом
    }
    else {
        tail->next = newNode;// Связываем новый узел с текущим хвостом
        newNode->prev = tail;// Устанавливаем указатель на предыдущий узел
        tail = newNode;// Обновляем хвост на новый узел
    }
}

// Метод вывода списка
void DoublyLinkedList::printList() const {
    Node2* current = head;// Начинаем с головы списка
    while (current) {
        cout << current->data << " ";// Выводим данные текущего узла
        current = current->next; // Переходим к следующему узлу
    }
    cout << endl;
}

// Метод для поиска минимального элемента
Node2* DoublyLinkedList::findMin() {
    Node2* minNode = head; // Начинаем с головы как минимального узла
    Node2* current = head; // Переменная для итерации по списку
    while (current) {
        if (current->data < minNode->data) { // Сравниваем данные узлов
            minNode = current; // Обновляем минимальный узел, если найден меньший
        }
        current = current->next; // Переходим к следующему узлу
    }
    return minNode; // Возвращаем найденный минимальный узел
}

//Метод для поиска максимального элемента
Node2* DoublyLinkedList::findMax() {
    Node2* maxNode = head; // Начинаем с головы как максимального узла
    Node2* current = head; // Переменная для итерации по списку
    while (current) {
        if (current->data > maxNode->data) { // Сравниваем данные узлов
            maxNode = current; // Обновляем максимальный узел, если найден больший
        }
        current = current->next; // Переходим к следующему узлу
    }
    return maxNode; // Возвращаем найденный максимальный узел
}

void DoublyLinkedList::removeElement(int value) {
    Node2* current = head; // Начинаем с головы списка

    while (current != nullptr) {
        if (current->data == value) { // Если нашли элемент с заданным значением
            if (current->prev != nullptr) {
                current->prev->next = current->next; // Переподключаем указатели предыдущего узла
            }
            else {
                head = current->next; // Если удаляем голову, обновляем голову списка
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev; // Переподключаем указатели следующего узла
            }
            else {
                tail = current->prev; // Если удаляем хвост, обновляем хвост списка
            }

            delete current; // Удаляем текущий узел
            return; // Завершаем выполнение метода после удаления
        }
        current = current->next; // Переходим к следующему узлу
    }
}

void DoublyLinkedList::swapSegments() {
    if (!head || !head->next) return; // Список пуст или из одного элемента

    Node2* minNode = findMin(); //Находим минимальный элемент
    Node2* maxNode = findMax();//Находим максимальный элемент

    if (minNode == maxNode) return; // Минимальный и максимальный элемент совпадают

    // Определяем порядок минимального и максимального элементов
    if (minNode->data > maxNode->data) {
        swap(minNode, maxNode);// Меняем местами указатели на минимальный и максимальный элементы, если нужно
    }

    // Инвертируем порядок элементов между minNode и maxNode
    Node2* start = minNode->next; // Начинаем с узла после минимального элемента
    Node2* end = maxNode->prev;// Начинаем с узла перед максимальным элементом

    while (start && end && start != end && start->prev != end) {
        // Меняем местами данные узлов
        swap(start->data, end->data);

        // Двигаем указатели к следующему и предыдущему узлам соответственно
        start = start->next;
        end = end->prev;
    }
}
