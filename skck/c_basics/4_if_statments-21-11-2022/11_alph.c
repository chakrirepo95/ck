//11) Write a program to read a character, and print if the character is alphabet or not ( whether entered character is A to Z or a to z)

#include<stdio.h>
int main()
{
	char c;
	printf("enter char value\n");
	scanf("%c",&c);
	if (c>64)
		if (c<91)
			printf("%c is Alphabet\n",c);
		else
			printf("%c is not Alphabet\n",c);
	if (c>96)
		if (c<123)
			printf("%c is Alphabet\n",c);
		else 
			printf("%c is not Alphabet\n",c);
	return 0;
}

