#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define N 10
#define A 1
#define B 20
#define C 5
#define D 8

int main()
{
	srand(time(0));
	int a[N];
	double b[N];
	FILE* fout = fopen("output.txt", "w");
	for (int i = 0; i < N; i++)
	{
		a[i] = A + (rand() % (B - A + 1));
		b[i] = C + (rand() / (RAND_MAX / (D - C)));
		fprintf(fout, "array_int[%d] = %d; array_double[%d] = %lf\n", i, a[i], i, b[i]);
		printf("%d ", a[i]);
	}
	fclose(fout);
	printf("\n");
	for (int i = 0; i < N; i++)
		printf("%.2lf ", b[i]);
	printf("\n");
	return 0;
}