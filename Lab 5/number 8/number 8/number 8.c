#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	char c;
	int digits[10] = { 0 };
	while ((c = fgetc(in)) != EOF)
		if (c >= '0' && c <= '9')
			digits[c - '0']++;

	for (int i = 0; i < 10; i++)
		if (digits[i] != 0)
			fprintf(out, "'%c' = %d\n", '0' + i, digits[i]);

	fclose(in);
	fclose(out);
	return 0;
}