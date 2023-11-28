#include "student.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

void printMenu() {
    std::cout << "\nMenu:\n"
        << "1. Add a student\n"
        << "2. Display students with grades 4 and 5\n"
        << "3. Display all students\n"
        << "4. Save students to file\n"
        << "5. Load students from file\n"
        << "6. Exit\n\n";
}

void displayAllStudents(const std::vector<Student>& students) {
    std::cout << "All students:\n";
    for (const Student& student : students) {
        std::cout << student;
    }
}

void saveStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const Student& student : students) {
            outFile << student.getName() << " " << student.getGroupNumber() << " "
                << student.getNumGrades();
            for (int i = 0; i < student.getNumGrades(); ++i) {
                outFile << " " << student.getGrades()[i];
            }
            outFile << "\n";
        }
        std::cout << "Students saved to file.\n";
    }
    else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void loadStudentsFromFile(std::vector<Student>& students, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        students.clear();
        while (!inFile.eof()) {
            std::string name;
            int groupNumber, numGrades;
            inFile >> name >> groupNumber >> numGrades;
            int* grades = new int[numGrades];
            for (int i = 0; i < numGrades; ++i) {
                inFile >> grades[i];
            }
            Student student(name, groupNumber, grades, numGrades);
            students.push_back(student);
        }
        std::cout << "Students loaded from file.\n";
    }
    else {
        std::cerr << "Unable to open file for reading.\n";
    }
}

int main() {
    std::vector<Student> students;

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n" << std::endl;
        switch (choice) {
        case 1: {
            
            Student student;
            std::cin >> student;
            students.push_back(student);
            break;
        }
        case 2: {
            // Сортировка по возрастанию среднего балла
            std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
                return a.calculateAverage() < b.calculateAverage();
                });

            std::cout << "\nStudents with grades 4 and 5:" << std::endl;
            bool found = false;
            for (const Student& student : students) {
                if (std::any_of(student.getGrades(), student.getGrades() + student.getNumGrades(),
                    [](int grade) { return grade == 4 || grade == 5; })) {
                    std::cout << student;
                    found = true;
                }
            }

            if (!found) {
                std::cout << "No students with grades 4 and 5 found." << std::endl;
            }
            break;
        }
        case 3:
            displayAllStudents(students);
            break;
        case 4: {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            saveStudentsToFile(students, filename);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            loadStudentsFromFile(students, filename);
            break;
        }
        case 6:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    // Вызываем деструкторы только в конце программы
    return 0;
}
