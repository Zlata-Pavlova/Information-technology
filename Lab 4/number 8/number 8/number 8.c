#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void PrintMatrix(int** matrix, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

void BubbleSort(int* array, int size)
{
	int tmp;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
}

void SortMatrix(int** matrix, int rowCount, int colCount)
{
	for (int i = 0; i < rowCount; i++)
		BubbleSort(matrix[i], colCount);
}

int main()
{
	int** matrix;
	int colCount, rowCount;
	srand(time(0));
	printf("Row count: ");
	scanf("%d", &rowCount);
	printf("Col count: ");
	scanf("%d", &colCount);
	matrix = (int**)malloc(sizeof(int*) * rowCount);
	for (int i = 0; i < rowCount; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * colCount);
		for (int j = 0; j < colCount; j++)
			matrix[i][j] = rand() % 100;
	}
	PrintMatrix(matrix, rowCount, colCount);
	SortMatrix(matrix, rowCount, colCount);
	PrintMatrix(matrix, rowCount, colCount);
	return 0;
}
