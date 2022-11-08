#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define SIZE 1024

int main()
{
	setlocale(0, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char strings[3][SIZE];
	char newStrings[100][SIZE] = { 0 };
	int n = 0;
	gets(strings[0]);
	gets(strings[1]);
	gets(strings[2]);

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			for (size_t k = 0; k < 3; k++)
			{
				if (i != j && j != k && i != k)
				{
					char* s1 = strings[i];
					char* s2 = strings[j];
					char* s3 = strings[k];
					char* s4 = newStrings[n];
					s4 = strcat(s4, s1);
					s4 = strcat(s4, s2);
					s4 = strcat(s4, s3);
					printf("%s\n", newStrings[n]);
					n++;
				}
			}
		}
	}

	return 0;
}