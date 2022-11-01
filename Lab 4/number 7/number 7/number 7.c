#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100

void BubbleSort(int* arr, int size, int reverse)
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if ((arr[j] > arr[j + 1] && reverse) || (arr[j] < arr[j + 1] && !reverse))
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int k = 1;
	int* array;
	int size;
	printf("Size: ");
	scanf("%d", &size);
	printf("K: ");
	scanf("%d", &k);
	array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		array[i] = -MAX + (rand() % (MAX * 2 + 1));
		printf("%d ", array[i]);
	}
	printf("\n");
	int r = 1;
	for (int i = 0; i < size; i += k)
	{
		BubbleSort(array + i, k, r);
		r = !r;
	}
	for (int i = 0; i < size; i++)
	{

		printf("%d ", array[i]);
		if ((i + 1) % k == 0)
			printf("|");
	}

	return 0;
}