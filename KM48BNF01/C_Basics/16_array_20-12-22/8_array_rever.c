/* 8) Write a program to reverse an array and print it (Reverse the array by swapping both edges of the array and move inside and repeat till middle of the array):  
Input : array1 ={1,2,3,4,5};
Output : array1 = {5,4,3,2,1};*/

#include<stdio.h>
int main()
{
	int i,j,p;
	int arr[5]={2,1,3,4,1};
	for(i=0,j=4;i<j;i++,j--)
	{
		p=arr[i];
		arr[i]=arr[j];
		arr[j]=p;
	}
	for(i=0;i<5;i++)
		printf(" %d ",arr[i]);
	return 0;
}

