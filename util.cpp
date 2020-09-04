#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"

void add_to_file(vector<int> &nums,string filename)
{
	cout<<filename;
	fstream file;
	file.open(filename,ios::out);
	for(int i=0;i<nums.size();i++)
	{
		file<<nums[i]<<endl;
	}
}
vector<int> ConvertToVector(const string& filename)
{
	ifstream file;
	file.open(filename);
	vector<string> nums;
	vector<int> num;
	string line;
	while(getline(file,line))
	{
		//cout<<line;
		nums.push_back(line);
	};
	for(int i=0;i<nums.size();i++)
	{
		//cout<<nums[i];
		stringstream s(nums[i]);
		int x=0;
		s >> x;
		num.push_back(x);
	}
	
	return num;
}
void printIntVector(vector<int> nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i];
	}
}
void printString(vector<string> nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<"\n"<<nums[i];
	}
}
