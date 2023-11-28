#include "filter.h"

bool containsWord(const std::string& sentence, const std::string& targetWord) {
    size_t found = sentence.find(targetWord);
    return found != std::string::npos;
}

void filterSentences(const std::string& filePath, const std::string& targetWord) {
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string sentence;

        while (std::getline(ss, sentence, '.')) {
            if (containsWord(sentence, targetWord)) {
                // Удаление пробела в начале строки, если он есть
                size_t startPos = sentence.find_first_not_of(" \t\n\r");
                if (startPos != std::string::npos) {
                    sentence = sentence.substr(startPos);
                }

                std::cout << sentence << "." << std::endl;
            }
        }
    }

    file.close();
}
