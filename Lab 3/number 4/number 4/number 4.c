#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 15

int main()
{
	int a[N];
	FILE* fin = fopen("input.txt", "r");
	if (fin == NULL)
	{
		printf("Can't open file!\n");
		return 1;
	}

	for (int i = 0; i < N; i++)
	{
		fscanf(fin, "%d", &a[i]);
		printf("%d ", a[i]);
		if (a[i] > 0)
			a[i] = -a[i];
		else
			a[i] = -a[i] % 10;
	}
	printf("\n");
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);

	printf("\n");
	return 0;
}