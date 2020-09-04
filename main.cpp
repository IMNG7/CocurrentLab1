#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include "util.h"
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

int main(int argc, char *args[])
{	int c;
	string input_file,output_file,algorithm;
	while(1)
	{
		int count = 0;
		
		static struct option long_options[] = {
			{"name",	no_argument,		0,	'n'},
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
						return 0;
						break;
			case 'o' : 	cout<<"\n\r File for output given \n\r";
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
	add_to_file(UnsortedArray,output_file);
	cout<<"\n\r Sorted Array:\n\r";
	printIntVector(UnsortedArray);

	return 0;
}
