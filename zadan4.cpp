#include "zadan4.h"
#include <sstream>
#include <unordered_map>

using namespace std;

// Реализация методов класса UnorderedSet

void Unordered::add(const string& element) {
    elements.insert(element); // Добавляем элемент в множество
}

void Unordered::remove(const string& element) {
    elements.erase(element); // Удаляем элемент из множества
}

Unordered Unordered::Union(const Unordered& other) const {
    Unordered result = *this; // Копируем текущее множество
    result.elements.insert(other.elements.begin(), other.elements.end()); // Добавляем элементы из другого множества
    return result;
}

Unordered Unordered::Except(const Unordered& other) const {
    Unordered result = *this; // Копируем текущее множество
    for (const auto& elem : other.elements) {
        result.elements.erase(elem); // Удаляем элементы, присутствующие в другом множестве
    }
    return result;
}

Unordered Unordered::Intersect(const Unordered& other) const {
    Unordered result;
    for (const auto& elem : elements) {
        if (other.elements.count(elem)) { // Если элемент присутствует в обоих множествах
            result.add(elem);
        }
    }
    return result;
}

bool Unordered::Contains(const string& element) const {
    return elements.count(element) > 0; // Проверяем, есть ли элемент в множестве
}

void Unordered::print() const {
    for (const auto& elem : elements) {
        cout << elem << " ";
    }
    cout << endl;
}

size_t Unordered::size() const {
    return elements.size(); // Возвращаем количество элементов
}

// Функция для поиска символов, встречающихся только в одном слове
void findUniqueSymbols(const std::string& text) {
    std::unordered_map<char, int> charCount; // Счетчик символов, где ключ - символ, значение - количество его появлений

    std::istringstream iss(text); // Создаем поток для разбивки текста на слова
    std::string word; // Переменная для хранения текущего слова
    while (iss >> word) { // Пока есть слова в потоке
        std::unordered_set<char> wordChars(word.begin(), word.end()); // Создаем множество уникальных символов текущего слова
        for (char c : wordChars) { // Проходим по каждому уникальному символу в слове
            charCount[c]++; // Увеличиваем счетчик для этого символа
        }
    }

    std::cout << "Символы, которые встречаются только в одном слове: "; // Сообщение для вывода результата
    for (const auto& pair : charCount) { // Проходим по каждому символу и его счетчику
        char ch = pair.first; // Получаем символ
        int count = pair.second; // Получаем количество появлений этого символа
        if (count == 1) { // Проверяем, встречается ли символ только в одном слове
            std::cout << ch << " "; // Выводим символ, если он уникален
        }
    }
    std::cout << std::endl; // Переход на новую строку после вывода всех уникальных символов
}
