#ifndef FILTER_H
#define FILTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool containsWord(const std::string& sentence, const std::string& targetWord);

void filterSentences(const std::string& filePath, const std::string& targetWord);

#endif // FILTER_H
