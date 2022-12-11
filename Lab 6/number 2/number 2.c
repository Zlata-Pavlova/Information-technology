#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 256

struct OS
{
	char name[LENGTH];
	char family[LENGTH];
	int popularity;
	int isFree;
};

typedef struct OS OperatingSystem;

int LoadFile(char* FileName, OperatingSystem** os)
{
	FILE* in = fopen(FileName, "r");
	char line[1024];
	int size = 0;
	char* ptr;
	int i;
	int index = 0;
	// Считаем кол-во строк в файле
	while (!feof(in))
	{
		fgets(line, 1024, in);
		size++;
	}
	(*os) = (OperatingSystem*)malloc(sizeof(OperatingSystem) * size);
	// Перемещаемся в начало файла
	fseek(in, 0, SEEK_SET);
	while (!feof(in))
	{
		fgets(line, 1024, in);
		ptr = strtok(line, ",");
		i = 0;
		while (ptr != NULL)
		{
			switch (i)
			{
			case 0:
				strcpy((*os)[index].name, ptr);
				break;
			case 1:
				strcpy((*os)[index].family, ptr);
				break;
			case 2:
				sscanf(ptr, "%d", &(*os)[index].popularity);
				break;
			case 3:
				sscanf(ptr, "%d", &(*os)[index].isFree);
				break;
			}
			i++;
			ptr = strtok(NULL, ",");
		}
		index++;
	}
	return size;
}

int main()
{
	setlocale(0, "RU");
	int size;
	double avgPopularity = 0.0;
	OperatingSystem* os;
	size = LoadFile("operating_systems.txt", &os);
	printf("Платные ОС:\n");
	for (int i = 0; i < size; i++)
	{
		if (os[i].isFree)
		{
			printf("%-20s%-10s%-4d%s\n", os[i].name, os[i].family, os[i].popularity,
				(os[i].isFree ? "Бесплатная" : "Платная"));
		}
		avgPopularity += os[i].popularity;
	}
	avgPopularity /= size;
	printf("Популярность меньше средней:\n");
	for (int i = 0; i < size; i++)
	{
		if (os[i].popularity < avgPopularity)
		{
			printf("%-20s%-10s%-4d%s\n", os[i].name, os[i].family, os[i].popularity,
				(os[i].isFree ? "Бесплатная" : "Платная"));
		}
	}

	return 0;
}