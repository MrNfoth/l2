#include "student.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "sentence_reader.h"

int main() {
    std::vector<STUDENT> students;

    // Чтение данных о студентах из консоли или другого источника

    // Сортировка студентов по возрастанию среднего балла
    std::sort(students.begin(), students.end());

    // Вывод на экран фамилий и номеров групп для студентов с оценками 4 и 5
    bool found = false;
    for (const auto& student : students) {
        if (std::any_of(student.getGrades().begin(), student.getGrades().end(), [](int grade) { return grade == 4 || grade == 5; })) {
            std::cout << "Name: " << student.getName() << ", Group: " << student.getGroupNumber() << std::endl;
            found = true;
        }
    }

    // Вывод сообщения, если студентов с оценками 4 и 5 нет
    if (!found) {
        std::cout << "No students with grades 4 or 5 found." << std::endl;
    }
	
	// Запрос слова от пользователя
    std::cout << "Enter a word to search for: ";
    std::string searchWord;
    std::cin >> searchWord;

    // Создание объекта SentenceReader и обработка файла
    SentenceReader sentenceReader("example.txt");
    sentenceReader.displaySentencesWithWord(searchWord);

    return 0;
}
