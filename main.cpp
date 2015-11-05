#include "spellingcorrector.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include "edit.h"

using std::cout;
using std::endl;

int main()
{
    clock_t start = clock();

    std::string train_file = "C:/Projects/Cpp/SpellingCorrector/data/count_big.txt";
    std::string test_file = "C:/Projects/Cpp/SpellingCorrector/data/spell-errors.txt";

    SpellingCorrector corrector(train_file);
    //    cout << corrector.GetWordNum() << endl;
    //    cout << Word2Edit("something").size() << endl;
    //    cout << corrector.Correct("lin") << endl;

    std::vector<std::pair<std::string, std::string>> instances;
    std::ifstream fin(test_file);
    char buffer[4096];
    if (!fin.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        exit(0);
    }
    std::stringstream ss;
    std::string word;
    std::string error;
    int count = 0;
    while (!fin.eof())
    {
        ++count;
        fin.getline(buffer, 4096);
        ss << buffer;
        if (buffer[0] == '\0') continue;
        ss >> word;
        word.erase(word.find(':'));
        while (!ss.eof())
        {
            ss >> error;
            int i_comma = error.find(',');
            if (i_comma > 0) error.erase(i_comma);
            instances.push_back(std::make_pair(word, error));
        }
        ss.clear();
    }
    fin.close();

    size_t right = 0;
    for (int i = 1000; i < 1100; ++i)
    {
        std::string answer = corrector.Correct(instances[i].second);
        if (answer == instances[i].first) ++right;
    }
    cout << "total: " << 100
         << "\tright: " << right
         << "\twrong: " << 100 - right
         << endl;


    cout<< 1000 * double(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}

