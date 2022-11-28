#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* in = fopen("input.txt", "r+");
	char c;
	int totalChars = 0, aCount = 0, oCount = 0, eCount = 0;
	while ((c = fgetc(in)) != EOF)
	{
		printf("%c", c);
		if (c == 'a')
			aCount++;
		if (c == 'o')
			oCount++;
		if (c == 'e')
			eCount++;
		totalChars++;
	}

	fprintf(in, "\na: %d\n", aCount);
	fprintf(in, "o: %d\n", oCount);
	fprintf(in, "e: %d\n", eCount);
	fprintf(in, "all: %d\n", totalChars);

	fclose(in);

	return 0;
}