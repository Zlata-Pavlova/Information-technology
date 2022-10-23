#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 10

int main()
{
	int initArray[N];
	int size = 0;
	int* newArray;
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		initArray[i] = rand() % 100;
		printf("%3d", initArray[i]);

		if (initArray[i] % 4 == 0 && initArray[i] % 2 == 0)
			size++;
	}
	printf("\n");
	newArray = (int*)malloc(sizeof(int) * size);

	for (int i = 0, j = 0; i < size; i++)
		if (initArray[i] % 4 == 0 && initArray[i] % 2 == 0)
		{
			newArray[j] = initArray[i];
			printf("%3d", newArray[j++]);
		}


	return 0;
}