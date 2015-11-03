#include "spellingcorrector.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

const int kBufferSize = 1024;

SpellingCorrector::SpellingCorrector(std::string filename)
{
    std::ifstream fin(filename);
    char buffer[kBufferSize];
    if (!fin.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        exit(0);
    }
    std::stringstream ss;
    std::string word;
    size_t count;
    while (!fin.eof())
    {
        fin.getline(buffer, kBufferSize);
        ss << buffer;
        ss >> word >> count;
        this->word_count_[word] = count;
        ss.clear();
    }
    fin.close();
}

SpellingCorrector::~SpellingCorrector()
{

}

size_t SpellingCorrector::GetWordNum()
{
    return this->word_count_.size();
}

