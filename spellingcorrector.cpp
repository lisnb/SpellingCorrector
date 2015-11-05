#include "spellingcorrector.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "edit.h"

const int kBufferSize = 1024;

SpellingCorrector::SpellingCorrector(const std::string &train_file)
{
    std::ifstream fin(train_file);
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
        if (buffer[0] == '\0') continue;
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

std::string SpellingCorrector::Correct(const std::string &error) const
{
    if (word_count_.find(error) != word_count_.end())
        return error;
    std::unordered_set<std::string> candidates = Word1Edit(error);
    std::string answer = this->MostFrequent(candidates);
    if (!answer.empty())
        return answer;
    candidates = Word2Edit(error);
    answer = this->MostFrequent(candidates);
    if (!answer.empty())
        return answer;
    return error;
}

std::string SpellingCorrector::MostFrequent(std::unordered_set<std::string> &candidates) const
{
    std::string answer;
    size_t max_count = 0;
    for (const auto &word : candidates)
    {
        if (word_count_.find(word) != word_count_.end() &&
                word_count_.at(word) > max_count)
        {
            max_count = word_count_.at(word);
            answer = word;
        }
    }
    return answer;
}
