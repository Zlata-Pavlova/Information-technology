#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100

void PrintMatrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int** matrix;
	int size, tmp;
	int minI = 0, minJ = 0;
	int min = MAX + 1;
	srand(time(0));
	printf("Size: ");
	scanf("%d", &size);
	matrix = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
		matrix[i] = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			matrix[i][j] = -MAX + (rand() % (MAX * 2 + 1));

	PrintMatrix(matrix, size);

	for (int i = 0; i < size; i++)
	{
		tmp = matrix[i][2];
		matrix[i][2] = matrix[i][size - 1];
		matrix[i][size - 1] = tmp;
	}

	PrintMatrix(matrix, size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (matrix[i][j] < min && matrix[i][j] > 0)
			{
				min = matrix[i][j];
				minI = i;
				minJ = j;
			}

	for (int i = 0; i < size; i++)
	{
		tmp = matrix[i][minJ];
		matrix[i][minJ] = matrix[minI][size - i - 1];
		matrix[minI][size - i - 1] = tmp;
	}

	PrintMatrix(matrix, size);

	return 0;
}