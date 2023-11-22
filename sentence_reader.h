#ifndef SENTENCE_READER_H
#define SENTENCE_READER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class SentenceReader {
public:
    explicit SentenceReader(const std::string& filename);

    void displaySentencesWithWord(const std::string& searchWord);

private:
    std::ifstream inputFile;

    std::string removePunctuation(const std::string& word);
};

#endif // SENTENCE_READER_H
