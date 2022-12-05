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
	while (line[i] != 0)
	{
		while (!isLetter(line[++i]));
		if (line[i] != 0)
		{
			while (line[i] != 0 && isLetter(line[i]))
			{
				printf("%c", line[i]);
				i++;
			}
			printf("\n");
		}
	}
	return 0;
}