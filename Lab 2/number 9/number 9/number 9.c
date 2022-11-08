#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#define SIZE 10

int main()
{
	setlocale(0, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char names[SIZE][1024];
	for (int i = 0; i < SIZE; i++)
		scanf("%s", &names[i]);
	printf("\n");
	for (int i = 0; i < SIZE; i++)
	{
		// strchr(str, c) - функция, для поиска вхождения символа (c) в строку (str)
		// Если символ найден, то возвращается указатель на него,
		// если нет, то null
		if (strchr("бвгджзйклмнпрстфхцчшщ", names[i][strlen(names[i]) - 1]))
			printf("%s\n", names[i]);
	}

	return 0;
}