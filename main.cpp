#include "spellingcorrector.h"

#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_set>

#include "edit.h"

using std::cout;
using std::endl;

int main()
{
    clock_t start = clock();

//    std::string filename = "C:/Projects/Cpp/SpellingCorrector/data/count_big.txt";
//    SpellingCorrector corrector(filename);
//    cout << corrector.GetWordNum() << endl;

//    cout << Word2Edit("aasdgfhdgfsh").size() << endl;
    Word2Edit("aasdgfhdgfsh");

    cout<< 1000 * double(clock() - start) / CLK_TCK << "ms" << endl;
    return 0;
}

