#ifndef ZADAN5_H
#define ZADAN5_H

#include <vector>
#include <string>
#include <fstream>

// Структура для хранения данных о каждом ученике
struct Student {
    std::string lastName;
    std::string firstName;
    int schoolNumber;
    int score;
};

// Класс, реализующий функционал словаря
class Dictionary {
public:
    Dictionary();  // Конструктор
    void addStudent(const Student& student); // Добавление студента
    void readDataFromFile(const std::string& filename);  // Чтение данных из файла
    void printStudents() const;  // Вывод студентов
    void computeExcellentScore();  // Вычисление минимального балла для отличников
    void removeStudent(const std::string& lastName); // Удаление ученика по фамилии

private:
    std::vector<Student> students;
};

#endif
