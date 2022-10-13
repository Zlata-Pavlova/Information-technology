#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

/*    0   1   2   3   4   5   6  <- counter
	-20 -19 -18 -17 -16 -15 -14  <- numbers
*/

void print_int(int start, int finish)
{
	FILE* fout = fopen("output.txt", "w");
	int counter = 0;
	for (int i = start; i <= finish; i++)
	{
		if (counter % 5 == 0)
		{
			printf("%d\n", i);
			fprintf(fout, "%d ", i);
		}
		counter++;
	}

	fclose(fout);
}

int main()
{
	print_int(-20, 15);
	return 0;
}