#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define A 1
#define B 20
#define N 10

int main()
{
	srand(time(0));
	int a[N];
	int elem[2];
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		a[i] = A + (rand() % (B - A + 1));
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		if (a[i] % 3 == 0)
		{
			elem[count] = a[i];
			count++;
			if (count == 2)
				break;
		}
	}
	if (count < 2)
		printf("Not found!");
	else
		printf("%d %d", elem[0], elem[1]);
	return 0;
}