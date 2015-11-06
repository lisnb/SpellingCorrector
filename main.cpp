#include "spellingcorrector.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <unordered_set>
#include <utility>
#include <vector>

#include "edit.h"

using std::cout;
using std::endl;

std::unordered_set<int> GenerateRandoms(size_t num, int lower, int upper)
{
    std::unordered_set<int> randoms;
    std::default_random_engine e1(std::time(0));
    std::uniform_int_distribution<int> uniform_dist(lower, upper);
    while (randoms.size() < num)
    {
        randoms.insert(uniform_dist(e1));
    }
    return randoms;
}

int main()
{
    clock_t start = clock();

    std::string train_file = "C:/Projects/Cpp/SpellingCorrector/data/count_big.txt";
    std::string test_file = "C:/Projects/Cpp/SpellingCorrector/data/test2.txt";

    SpellingCorrector corrector(train_file);
//    cout << corrector.GetWordNum() << endl;
//    cout << Word2Edit("play_grood").size() << endl;
//    cout << corrector.Correct("play_grood") << endl;

    std::vector<std::pair<std::string, std::string>> instances;
    std::ifstream fin(test_file);
    std::string buffer;
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
        getline(fin, buffer);
        if (buffer.empty()) continue;
        ss << buffer;
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
    size_t total = instances.size();
    for (size_t i = 0; i < instances.size(); ++i)
    {
        std::string answer = corrector.Correct(instances[i].second);
        cout << instances[i].second << "\t"
             << answer << "\t"
             << instances[i].first << endl;
        if (answer == instances[i].first)
            ++right;
    }
    cout << "Total: " << total
         << "\tRight: " << right
         << "\tWrong: " << total - right
         << endl;

    cout << "Accuracy: " << int(100.0 * right / total) << "%" << endl;

    cout<< 1000 * double(clock() - start) / CLOCKS_PER_SEC << "ms" << endl;
    return 0;
}

