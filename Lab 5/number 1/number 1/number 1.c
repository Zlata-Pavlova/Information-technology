#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	// Открытие файла на перезапись
	FILE* out = fopen("output.txt", "w");
	int n, m;
	printf("N: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d ", rand() % 100);
	fclose(out);
	// Открытие файла на дозапись
	out = fopen("output.txt", "a");
	printf("M: ");
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		fprintf(out, "%c ", rand() % 128);
	fclose(out);
	return 0;
}