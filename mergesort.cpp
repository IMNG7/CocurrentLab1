#include "mergesort.h"


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
