#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100


int main()
{
	int* array;
	int size, min = 0, max = 0, tmp;
	printf("Size: ");
	scanf("%d", &size);
	srand(time(0));
	array = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		array[i] = -MAX + (rand() % (MAX * 2 + 1));
		if (array[i] > array[max])
			max = i;
		if (array[i] < array[min])
			min = i;
		printf("%d ", array[i]);
	}
	printf("\n");

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	printf("%d %d\n", min, max);
	min++;
	max--;
	while (min < max)
	{
		tmp = array[min];
		array[min] = array[max];
		array[max] = tmp;
		min++;
		max--;
	}

	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);

	return 0;
}