#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

void mergesort(vector<int> &nums,int left,int right);
void merge(vector<int> &nums,int left,int middle,int right);

#endif