#ifndef UTIL_H
#define UTIL_H

#include <vector>

using namespace std;

void printString(vector<string>);
void printIntVector(vector<int>);
vector<int> ConvertToVector(const string&);
void add_to_file(vector<int> &nums,string filename);

#endif