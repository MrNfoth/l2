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
        std::cout << "����:" << std::endl;
        std::cout << "1. ������ ����� ��� �����" << std::endl;
        std::cout << "2. ������ ����� �����" << std::endl;
        std::cout << "3. �����" << std::endl;

        int choice;
        std::cout << "�������� ����� (1-3): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "������� ����� ��� �����: ";
            std::cin.ignore(); // ������� ������ ����� ����� getline
            std::getline(std::cin, filePath);
            break;

        case 2:
            std::cout << "������� ����� ����� ��� ������: ";
            std::cin >> targetWord;
            break;

        case 3:
            exitMenu = true;
            break;

        default:
            std::cout << "�������� �����. ����������, �������� �� 1 �� 3." << std::endl;
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

// ������� ��� ��������, �������� �� ������ �������� �����
bool containsWord(const string& sentence, const string& targetWord) {
    // ���������� ����� ���� �������� � ����������� �� ����������
    size_t found = sentence.find(targetWord);
    return found != string::npos;
}

// ������� ��� ���������� �����������
void filterSentences(const string& filePath, const string& targetWord) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "�� ������� ������� ����." << endl;
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

    cout << "������� ��� �����: ";
    getline(cin, filePath);

    cout << "������� ����� ��� ������: ";
    cin >> targetWord;

    filterSentences(filePath, targetWord);

    return 0;
}
*/