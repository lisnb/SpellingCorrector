#ifndef EDIT_H
#define EDIT_H

#include <string>
#include <unordered_set>

//std::unordered_set<std::string> Word1Edit(const std::string &error);
//std::unordered_set<std::string> Word2Edit(const std::string &error);

void Word1Edit(std::unordered_set<std::string> &uset1, const std::string &error);
void Word2Edit(std::unordered_set<std::string> &uset2, const std::string &error);

#endif // EDIT_H

