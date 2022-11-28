#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 1024

int main()
{
	FILE* in = fopen("input.txt", "r");
	char c;
	int wordCount = 0;
	char line[LENGTH];
	char* ptr;
	// Разделители
	char delimiter[256] = " \n\t,.!?:;";

	// Чтение в переменную line строки из файла до тех пор, пока возможно читать.
	while (fgets(line, LENGTH, in))
	{
		// strtok(строкаб разделители) - функция, для разделения строки на части по разделителям
		// Перемещаемся по кусочкам строки, которые разделены одним из разделителей
		ptr = strtok(line, delimiter);
		while (ptr != NULL)
		{
			// ptr - указатель на кусочек (слово)
			if (strlen(ptr) % 2 == 0)
			{
				printf("%s\n", ptr);
				wordCount++;
			}
			// Переход к следующему кусочку
			ptr = strtok(NULL, delimiter);
		}
	}

	printf("Count: %d", wordCount);

	fclose(in);
	return 0;
}