#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100

int main()
{
	int* array;
	int size;
	printf("Size: ");
	scanf("%d", &size);
	srand(time(0));
	array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		array[i] = -MAX + (rand() % (MAX * 2 + 1));
		printf("%d ", array[i]);
	}
	printf("\n");
	int tmp;
	int pos = 0;
	for (int i = 0; i < size - pos; i++)
	{
		if (array[i] % 2 != 0 && array[i] < 0)
		{
			tmp = array[i];
			for (int j = i; j < size - 1; j++)
				array[j] = array[j + 1];
			array[size - 1] = tmp;
			pos++;
			i--;
		}
	}

	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
	return 0;
}