#include "sentence_reader.h"

int main() {
    std::cout << "===== Sentence Reader Menu =====" << std::endl;
    std::cout << "1. Enter a word to search for" << std::endl;
    std::cout << "2. Exit" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "Enter a word to search for: ";
            std::string searchWord;
            std::cin >> searchWord;

            // Создание объекта SentenceReader и обработка файла
            SentenceReader sentenceReader("example.txt");
            sentenceReader.displaySentencesWithWord(searchWord);
            break;
        }
        case 2: {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice. Exiting the program." << std::endl;
            break;
        }
    }

    return 0;
}
