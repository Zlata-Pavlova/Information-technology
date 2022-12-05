#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	char c;

	while ((c = fgetc(in)) != EOF)
	{
		fprintf(out, "%c", (c == 'a' ? 'o' : c == 'o' ? 'e' : c == 'e' ? 'a' : c));
	}

	fclose(in);
	fclose(out);
	return 0;
}