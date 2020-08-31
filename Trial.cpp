#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void printString(vector<string>);
void printIntVector(vector<int>);
vector<int> ConvertToVector(const string&);

int main(int argc, char **args)
{
	string filename(args[1]);
	vector<int> UnsortedArray = ConvertToVector(filename);
	//vector<string> UnsortedArray = ConvertToVector(filename);
	printIntVector(UnsortedArray);
	//printString(UnsortedArray);
	return 0;
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
		cout<<"\n"<<nums[i];
	}
}
void printString(vector<string> nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<"\n"<<nums[i];
	}
}