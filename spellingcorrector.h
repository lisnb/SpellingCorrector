#ifndef SPELLINGCORRECTOR_H
#define SPELLINGCORRECTOR_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class SpellingCorrector
{
public:
    SpellingCorrector(const std::string &train_file);
    ~SpellingCorrector();
    int GetWordNum() const;
    std::string Correct(const std::string &error) const;
private:
    std::string MostFrequent(std::unordered_set<std::string> &candidates) const;
    std::unordered_map<std::string, size_t> word_count_;
};

inline int SpellingCorrector::GetWordNum() const
{
    return this->word_count_.size();
}

#endif // SPELLINGCORRECTOR_H
