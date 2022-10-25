#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
#define INF 101

int GetMaxInCol(int** matrix, int row, int colIndex)
{
	int max = -INF;
	for (int i = 0; i < row; i++)
		if (matrix[i][colIndex] < 0 && matrix[i][colIndex] > max)
			max = matrix[i][colIndex];
	return max;
}

int main()
{
	int** matrix;
	int* maxCols;
	int col, row;
	printf("Cols count: ");
	scanf("%d", &col);
	printf("Rows count: ");
	scanf("%d", &row);

	matrix = (int**)malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
		matrix[i] = (int*)malloc(sizeof(int) * col);

	maxCols = (int*)malloc(sizeof(int) * col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = -MAX + (rand() % (MAX * 2 + 1));
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < col; i++)
	{
		maxCols[i] = GetMaxInCol(matrix, row, i);
	}

	printf("\n");
	for (int j = 0; j < col; j++)
		printf("%4d", maxCols[j]);

	return 0;
}