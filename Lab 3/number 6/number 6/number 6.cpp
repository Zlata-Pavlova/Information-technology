#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 10
#define A -10
#define B 10


int main()
{
	srand(time(0));
	int sum = 0, sum2 = 0, min = B + 1;
	int init_array[N][M];
	int new_array[N][M];
	FILE* fout = fopen("array.txt", "w");
	FILE* fin;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			init_array[i][j] = A + (rand() % (B - A + 1));
			fprintf(fout, "%-4d", init_array[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
	fin = fopen("array.txt", "r");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			fscanf(fout, "%d", &new_array[i][j]);
			printf("%4d", new_array[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (new_array[i][j] > 0)
			{
				sum += new_array[i][j];
			}
		}
	for (int i = 0; i < M; i++)
		sum2 += new_array[3][i];

	printf("\nSum = %d\n", sum);
	printf("Average = %f\n", (float)sum2 / M);
	// Проверка на квадратный массив, т.к. у прочих нет главной диагонали.
	if (N == M)
	{
		for (int i = 1; i < N; i++)
		{
			if (new_array[i][i] > 0 && new_array[i][i] < min)
			{
				min = new_array[i][i];
			}
		}
		printf("Min = %d", min);
	}
	fclose(fin);
	return 0;
}