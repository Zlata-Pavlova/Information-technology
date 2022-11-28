#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#define N 5
#define LENGTH 128

int main()
{
	char names[N][LENGTH];

	for (int i = 0; i < N; i++)
		scanf("%s", &names[i]);

	for (int i = 0; i < N; i++)
		printf("%s\n", names[i]);

	return 0;
}