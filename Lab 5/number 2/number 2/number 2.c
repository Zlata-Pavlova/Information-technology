#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* in = fopen("input.txt", "r");
	char c;
	while ((c = fgetc(in)) != EOF)
		printf("%c", c);
	fclose(in);
	return 0;
}