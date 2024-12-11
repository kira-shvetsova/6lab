#include "zadan3.h"

// Добавление элемента в коллекцию
void UnorderedSet::add(const string& value) {
    elements.insert(value); // Добавляет элемент, если его нет
}

// Удаление элемента из коллекции
void UnorderedSet::remove(const string& value) {
    elements.erase(value); // Удаляет элемент, если он существует
}

// Объединение двух коллекций
UnorderedSet UnorderedSet::Union(const UnorderedSet& other) const {
    UnorderedSet result;
    result.elements = elements; // Копируем текущие элементы
    for (const auto& elem : other.elements) {
        result.add(elem); // Добавляем элементы из второй коллекции
    }
    return result;
}

// Разность двух коллекций
UnorderedSet UnorderedSet::Except(const UnorderedSet& other) const {
    UnorderedSet result;
    for (const auto& elem : elements) {
        if (!other.Contains(elem)) {
            result.add(elem); // Добавляем элементы, которых нет во второй коллекции
        }
    }
    return result;
}

// Пересечение двух коллекций
UnorderedSet UnorderedSet::Intersect(const UnorderedSet& other) const {
    UnorderedSet result;
    for (const auto& elem : elements) {
        if (other.Contains(elem)) {
            result.add(elem); // Добавляем только общие элементы
        }
    }
    return result;
}

// Проверка наличия элемента
bool UnorderedSet::Contains(const string& value) const {
    return elements.find(value) != elements.end();
}

// Получение всех элементов в виде вектора
vector<string> UnorderedSet::getElements() const {
    return vector<string>(elements.begin(), elements.end());
}

// Вывод множества
void UnorderedSet::print() const {
    for (const auto& elem : elements) {
        cout << elem << " ";
    }
    cout << endl;
}
