#include "sentence_reader.h"

SentenceReader::SentenceReader(const std::string& filename) {
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }
}

void SentenceReader::displaySentencesWithWord(const std::string& searchWord) {
    if (!inputFile.is_open()) {
        std::cerr << "File is not open." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            word = removePunctuation(word);

            if (word == searchWord) {
                std::cout << line << std::endl;
                break;
            }
        }
    }
}

std::string SentenceReader::removePunctuation(const std::string& word) {
    std::string result;
    std::copy_if(word.begin(), word.end(), std::back_inserter(result), [](char c) {
        return !std::ispunct(c);
    });
    return result;
}
