#ifndef SPELLINGCORRECTOR_H
#define SPELLINGCORRECTOR_H

#include <string>
#include <unordered_map>

class SpellingCorrector
{
public:
    SpellingCorrector(const std::string &filename);
    ~SpellingCorrector();
    int GetWordNum();
    std::string Correct(const std::string &error);
private:
    std::unordered_map<std::string, size_t> word_count_;
};

inline int SpellingCorrector::GetWordNum()
{
    return this->word_count_.size();
}

#endif // SPELLINGCORRECTOR_H
