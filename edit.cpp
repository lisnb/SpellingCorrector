#include "edit.h"

#include <string>
#include <unordered_set>

const std::string kAlphabet = "abcdefghijklmnopqrstuvwxyz";

std::unordered_set<std::string> Word1Edit(const std::string &error)
{
    std::unordered_set<std::string> words1;
    std::string word;
    int len = error.size();
    int len_alphabet = kAlphabet.length();
    for (int i = 0; i < len + 1; ++i)
    {
        for (int j = 0; j < len_alphabet; ++j)
        {
            word = error;
            word.insert(i, 1, kAlphabet[j]);
            words1.insert(word);
        }
    }
    for (int i = 0; i < len; ++i)
    {
        word = error;
        word.erase(i, 1);
        words1.insert(word);
    }
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len_alphabet; ++j)
        {
            word = error;
            word[i] = kAlphabet[j];
            words1.insert(word);
        }
    }
    for (int i = 0; i < len - 1; ++i)
    {
        word = error;
        std::swap(word[i], word[i + 1]);
        words1.insert(word);
    }
    return words1;
}

std::unordered_set<std::string> Word2Edit(const std::string &error)
{
    std::unordered_set<std::string> words2;
    std::unordered_set<std::string> tmp;
    for (const auto &word1 : Word1Edit(error))
    {
        tmp = Word1Edit(word1);
        for (const auto &word : tmp)
        {
            words2.insert(word);
        }
    }
    return words2;
}
