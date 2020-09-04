#include "quicksort.h"

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