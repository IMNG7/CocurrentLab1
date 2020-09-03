#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

using namespace std;

void printString(vector<string>);
void printIntVector(vector<int>);
vector<int> ConvertToVector(const string&);
void mergesort(vector<int> &nums,int left,int right);
void merge(vector<int> &nums,int left,int middle,int right);
void quicksort(vector<int> &nums,int left,int right);
int seperate(vector<int> &nums,int left,int right);

int main(int argc, char *args[])
{	int c;
	string input_file,output_file,algorithm;
	while(1)
	{
		int count = 0;
		
		static struct option long_options[] = {
			{"name",	no_argument,	0,	'n'},
			{"output",	required_argument,	0,	'o'},
			{"alg", 	required_argument,	0,	'a'},
			{0,			0,					0,	0}
		};
		c= getopt_long(argc,args,"no:a:",long_options,&count);
		if(c==-1)	break;
		switch(c)
		{
			case 'n' :	
						cout<<"\n\r Name:NITIK SATISH GUPTA:";
						break;
			case 'o' : 	
						output_file = optarg;
						break;
			case 'a' :	
						algorithm = optarg;
						break;
			default	:	
						break;
		}
	}
	if(optind < argc)
	{
		while(optind < argc)
		{	
			input_file = args[optind++];
		}
	}

	string filename(input_file);
	vector<int> UnsortedArray = ConvertToVector(filename);
	cout<<"\n\r Input Array: \n\r";
	printIntVector(UnsortedArray);
	if(algorithm == "merge")
	{
		mergesort(UnsortedArray,0,UnsortedArray.size()-1);
		cout<<"\n\rDoing mergesort";
	}
	else if(algorithm == "quick")
	{	
		quicksort(UnsortedArray,0,UnsortedArray.size()-1);
		cout<<"\n\rDoing quicksort";
	}
	else
		cout<<"Wrong Choice";
	cout<<"\n\r Sorted Array:\n\r";
	printIntVector(UnsortedArray);

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
void mergesort(vector<int> &nums,int left,int right)
{
	if(left<right)
	{
		int middle = left+((right-left)/2);
		mergesort(nums,left,middle);
		mergesort(nums,middle+1,right);
		merge(nums,left,middle,right);
	}
}
void merge(vector<int> &nums,int left,int middle,int right)
{
	int leftsize = middle - left + 1;
	int rightsize = right - middle;
	int lefttemp[leftsize],righttemp[rightsize];
	int i,j,k;
	for(i=0;i<leftsize;i++)
	{
		lefttemp[i] = nums[i+left];
	}
	for(i=0;i<rightsize;i++)
	{
		righttemp[i] = nums[middle+i+1];
	}
	i=0;j=0;k=left;
	while(i<leftsize && j<rightsize)
	{
		if(lefttemp[i]<=righttemp[j])
		{
			nums[k]=lefttemp[i];
			i++;
		}
		else
		{
			nums[k]=righttemp[j];
			j++;
		}
		k++;
	}
	while(i<leftsize)
	{
		nums[k]=lefttemp[i];
		i++;
		k++;
	}
	while(j<rightsize)
	{
		nums[k]=righttemp[j];
		j++;
		k++;
	}
}
void quicksort(vector<int> &nums,int left,int right)
{
	if(left<right)
	{
		int sep = seperate(nums,left,right);
		quicksort(nums,left,sep-1);
		quicksort(nums,sep+1,right);
	}
}
int seperate(vector<int> &nums,int left,int right)
{
	int pivot = nums[right];
	int i=left-1,temp;
	for(int j=left;j<right;j++)
	{
		if(nums[j]<pivot)
		{
			i++;
			temp=nums[i];
			nums[i]=nums[j];
			nums[j]=temp;
		}
	}
	temp=nums[i+1];
	nums[i+1]= nums[right];
	nums[right] = temp;
	return (i+1);
}