#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 10
#define A -10
#define B 10

int main()
{
	int matrix[N][M];
	int* array;
	int size = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matrix[i][j] = A + (rand() % (B - A + 1));
			printf("%-4d", matrix[i][j]);

			if (i % 2 == 0 && j % 2 != 0 && matrix[i][j] < 0)
				size++;
		}
		printf("\n");
	}
	printf("\n");
	array = (int*)malloc(sizeof(int) * size);
	int arrayIndex = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (i % 2 == 0 && j % 2 != 0 && matrix[i][j] < 0)
			{
				array[arrayIndex] = matrix[i][j];
				printf("%-4d", array[arrayIndex]);
			}

	return 0;
}
