/* 5) Write the following program.
Declare an integer variable ‘size’.
Take the value of ‘size’ from user using scanf.
Declare an array of any datatype, and give the integer variable ‘size’, in place of size of the array  and initialize it to some values.(syntax: float array[size] = {1.0,2.5};)
Using for loop, try to take user input using scanf. Loop should execute ‘size’ number of times.
Using for loop, print the elements of the array.*/

#include<stdio.h>
int main()
{
	int i,size;
	scanf("%d",& size);
	float arr[size];
	for (i=0;i<size;i++)
		scanf("%e",& arr[i]);
	for (i=0;i<size;i++)
		printf("%f",arr[i]);
	return 0;
}


