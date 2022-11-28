#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define LENGTH 1024

int isLetter(char c)
{
	return (c > 64 && c < 91) || (c > 96 && c < 123);
}

int main()
{
	char line[LENGTH] = " hello, world! hey";
	int i = 0;
	while (i < strlen(line))
	{
		if (isLetter(line[i]))
		{

		}
	}
	return 0;
}