#include "zadan5.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

// Конструктор
Dictionary::Dictionary() {}

// Добавление ученика
void Dictionary::addStudent(const Student& student) {
    students.push_back(student);
}

// Чтение данных из файла
void Dictionary::readDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Student student;
        ss >> student.lastName >> student.firstName >> student.schoolNumber >> student.score;
        addStudent(student);
    }
}

// Вывод студентов
void Dictionary::printStudents() const {
    for (const auto& student : students) {
        std::cout << student.lastName << " " << student.firstName << " "
            << student.schoolNumber << " " << student.score << std::endl;
    }
}
// Реализация функции удаления студента
void Dictionary::removeStudent(const std::string& lastName) {
    // Удаляем студентов с заданной фамилией из вектора
    auto it = std::remove_if(students.begin(), students.end(),
        [&lastName](const Student& student) {
            return student.lastName == lastName; // Сравниваем фамилию
        });

    if (it != students.end()) { // Если были найдены студенты для удаления
        students.erase(it, students.end()); // Удаляем их из вектора
        std::cout << "Студент(ы) с фамилией '" << lastName << "' удалены." << std::endl;
    }
    else {
        std::cout << "Студент с фамилией '" << lastName << "' не найден." << std::endl;
    }
}
void Dictionary::computeExcellentScore() {
    // Проверяем, есть ли студенты в списке
    if (students.empty()) {
        std::cout << "Нет студентов!" << std::endl; // Если список студентов пуст, выводим сообщение
        return; // Завершаем выполнение функции
    }

    // Создаем вектор для хранения баллов студентов
    std::vector<int> scores;
    for (const auto& student : students) {
        scores.push_back(student.score); // Добавляем балл каждого студента в вектор
    }

    // Сортируем баллы студентов по убыванию
    std::sort(scores.begin(), scores.end(), std::greater<int>());

    // Определяем количество студентов, которые могут получить "отлично" (20% от общего числа)
    int excellentCount = scores.size() / 5; // Рассчитываем 20% от общего количества студентов
    if (excellentCount == 0) {
        excellentCount = 1; // Если студентов меньше 5, то хотя бы один студент получит "отлично"
    }

    // Находим минимальный балл среди студентов, получивших "отлично"
    int minExcellentScore = scores[excellentCount - 1]; // Индекс - 1, так как индексация начинается с 0

    // Выводим минимальный балл для отличников
    std::cout << "Минимальный балл для отличников: " << minExcellentScore << std::endl;
}
