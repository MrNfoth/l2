#include "filter.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
using namespace std;
int main() {
    std::locale::global(std::locale(""));

    std::string filePath, targetWord;
    bool exitMenu = false;

    while (!exitMenu) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Ввести новое имя файла" << std::endl;
        std::cout << "2. Ввести новое слово" << std::endl;
        std::cout << "3. Выход" << std::endl;

        int choice;
        std::cout << "Выберите опцию (1-3): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите новое имя файла: ";
            std::cin.ignore(); // Очистка буфера ввода перед getline
            std::getline(std::cin, filePath);
            break;

        case 2:
            std::cout << "Введите новое слово для поиска: ";
            std::cin >> targetWord;
            break;

        case 3:
            exitMenu = true;
            break;

        default:
            std::cout << "Неверный выбор. Пожалуйста, выберите от 1 до 3." << std::endl;
            break;
        }

        if (!exitMenu) {
            filterSentences(filePath, targetWord);
        }
    }

    return 0;
}

/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
using namespace std;

// Функция для проверки, содержит ли строка заданное слово
bool containsWord(const string& sentence, const string& targetWord) {
    // Реализация может быть уточнена в зависимости от требований
    size_t found = sentence.find(targetWord);
    return found != string::npos;
}

// Функция для фильтрации предложений
void filterSentences(const string& filePath, const string& targetWord) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string sentence;

        while (getline(ss, sentence, '.')) {
            if (containsWord(sentence, targetWord)) {
                cout << sentence << "." << endl;
            }
        }
    }

    file.close();
}

int main() {
    std::locale::global(std::locale(""));
    string filePath, targetWord;

    cout << "Введите имя файла: ";
    getline(cin, filePath);

    cout << "Введите слово для поиска: ";
    cin >> targetWord;

    filterSentences(filePath, targetWord);

    return 0;
}
*/