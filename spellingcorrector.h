#ifndef SPELLINGCORRECTOR_H
#define SPELLINGCORRECTOR_H

#include <string>
#include <unordered_map>

class SpellingCorrector
{
public:
    SpellingCorrector(std::string filename);
    ~SpellingCorrector();
    size_t GetWordNum();
private:
    std::unordered_map<std::string, size_t> word_count_;
};

#endif // SPELLINGCORRECTOR_H
