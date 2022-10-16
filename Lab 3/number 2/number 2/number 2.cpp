#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define N 20
#define A 5
#define B 25

int main()
{
	int array[N];
	for (int i = 0, x = A; i < N; i++, x += 1)
	{
		array[i] = -3 * x / 2 + (x * x);
		printf("%d ", array[i]);
	}
	return 0;
}
