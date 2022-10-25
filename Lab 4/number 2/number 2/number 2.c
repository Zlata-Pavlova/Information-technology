#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
#define INF 101

/// <summary>
/// Функция нахождения минимального значения в строке.
/// </summary>
/// <param name="matrix">Матрица, в которой идёт поиск</param>
/// <param name="rowIndex">Столбец, в котором идёт поиск</param>
/// <param name="col">Кол-во элементов в строке</param>
/// <returns>Минимальное значение, либо INF, если не найдено ни одного значения</returns>
int GetMinValueInRow(int** matrix, int rowIndex, int col)
{
	int min = INF;
	for (int i = 1; i < col; i++)
		if (matrix[rowIndex][i] % 4 == 0 && matrix[rowIndex][i] < min)
			min = matrix[rowIndex][i];
	return min;
}

/// <summary>
/// Функция нахождения суммы положительных элементов в столбце
/// </summary>
/// <param name="matrix">Матрица, в которой идёт поиск</param>
/// <param name="row">Кол-во строк в матрице</param>
/// <param name="colIndex">Строка, в которой идёт поиск</param>
/// <returns>Сумма положительных элементов в столбце</returns>
int GetSumInCol(int** matrix, int row, int colIndex)
{
	int sum = 0;
	for (int i = 1; i < row; i++)
		if (matrix[i][colIndex] > 0)
			sum += matrix[i][colIndex];
	return sum;
}

/**
 *  matrix[номер строки][номер столбца]
 */

int main()
{
	int** matrix;
	int* minsRows;
	int* sumCols;
	int col, row;
	printf("Cols count: ");
	scanf("%d", &col);
	printf("Rows count: ");
	scanf("%d", &row);

	// Выделение памяти для двумерного массива
	// Сначала выделяется память для строк
	matrix = (int**)malloc(sizeof(int*) * row);
	// Далее, для каждой строки выделяется память на кол-во элементов в этой строке
	for (int i = 0; i < row; i++)
		matrix[i] = (int*)malloc(sizeof(int) * col);
	// Выделение памяти для дополнительных одномерных массивов
	minsRows = (int*)malloc(sizeof(int) * col);
	sumCols = (int*)malloc(sizeof(int) * row);

	// Циклы генерации матрицы и вывода её на экран
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

	// Обход строк и столбцов для формирования одномерных массивов по заданию
	for (int i = 0; i < row; i++)
		minsRows[i] = GetMinValueInRow(matrix, i, col);
	for (int i = 0; i < col; i++)
		sumCols[i] = GetSumInCol(matrix, row, i);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%4d", matrix[i][j]);

		if (minsRows[i] == INF)
			printf("\tNot found!\n");
		else
			printf("\t%d\n", minsRows[i]);
	}
	printf("\n");
	for (int j = 0; j < col; j++)
		printf("%4d", sumCols[j]);

	return 0;
}