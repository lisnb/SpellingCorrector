#include "spellingcorrector.h"

#include <iostream>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;

std::unordered_set<std::string> Word1Edit(std::string word)
{
    std::unordered_set<std::string> words;
    return words;
}

int main()
{
    std::string filename = "C:/Projects/Cpp/SpellingCorrector/data/count_big.txt";
    SpellingCorrector corrector(filename);
    cout << corrector.GetWordNum() << endl;
    return 0;
}

