#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define A -10
#define B 10

int getMinMod3Row(double matr[N][N])
{
	int minI = 0, minJ = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// Невозможно проверить кратность вещественного числа!!!!!
			if (((int)matr[i][j]) % 3 == 0 && abs(matr[i][j]) < abs(matr[minI][minJ]))
			{
				minI = i;
				minJ = j;
			}
		}
	}
	return minI;
}

int getSumLastDigitsEvenValues(double matr[N][N])
{
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			// Невозможно проверить чётность вещественного числа!!!!!
			if (((int)matr[i][j]) % 2 == 0)
				sum += ((int)matr[i][j]) % 10;
		}
	return sum;
}

double getDiff(double matr[N][N])
{
	double max = 0;
	double min = B + 1;
	for (int i = 0; i < N; i++)
	{
		if (matr[i][i] > 0 && matr[i][i] > max)
			max = matr[i][i];
		if (matr[i][N - i - 1] > 0 && ((int)matr[i][N - i - 1]) % 6 == 0 && matr[i][N - i - 1] < min)
			min = matr[i][i];
	}
	return max - min;
}

int main()
{
	setlocale(0, "RU");
	srand(time(0));
	double matrix[N][N];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = A + rand() * (B - A) / (double)RAND_MAX;
			printf("%6.2f", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\nСтрока с нименьшим по абс. значению элементом: %d\n", getMinMod3Row(matrix));
	printf("Сумма последних цифр чётных элементов: %d\n", getSumLastDigitsEvenValues(matrix));
	printf("Разница между максимальным и минимальным (см. задание): %.2f\n", getDiff(matrix));

	return 0;
}
