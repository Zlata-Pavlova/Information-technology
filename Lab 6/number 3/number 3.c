#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 256
#define AGR_COUNT 3
#define CULT_SIZE 100

struct _Agriculture
{
	char name[LENGTH];
	float cropVolume;
	float sowingArea;
};

typedef struct _Agriculture Agriculture;

struct _Agronomy
{
	char region[LENGTH];
	int size;
	Agriculture agricultures[CULT_SIZE];
};

typedef struct _Agronomy Agronomy;

int main()
{
	Agronomy agronomy[AGR_COUNT] = { 0 };
	int agrSize = 0;
	Agronomy agronomyTemp;
	FILE* in = fopen("agronomy.txt", "r");
	int index = 0;
	char line[1024];
	char* ptr;
	int i, contains;

	while (!feof(in))
	{
		fgets(line, 1024, in);
		if (strlen(line) == 0)
			break;
		ptr = strtok(line, ",");
		i = 0;
		while (ptr != NULL)
		{
			switch (i)
			{
			case 0:
				contains = 0;
				for (size_t r = 0; r < agrSize; r++)
				{
					if (strcmp(ptr, agronomy[r].region) == 0)
					{
						contains = 1;
						break;
					}
				}
				if (!contains)
				{
					strcpy(agronomy[agrSize].region, ptr);
					agronomy[agrSize].size = 0;
					agrSize++;
				}
				break;
			case 1:
				strcpy(agronomy[agrSize - 1].agricultures[agronomy[agrSize - 1].size].name, ptr);
				break;
			case 2:
				sscanf(ptr, "%f", &agronomy[agrSize - 1].agricultures[agronomy[agrSize - 1].size].cropVolume);
				break;
			case 3:
				sscanf(ptr, "%f", &agronomy[agrSize - 1].agricultures[agronomy[agrSize - 1].size].sowingArea);
				agronomy[agrSize - 1].size++;
				break;
			}
			i++;
			ptr = strtok(NULL, ",");
		}
	}

	// Task 1
	for (size_t i = 0; i < agrSize; i++)
	{
		float sowingAreaSum = 0.0;
		for (size_t j = 0; j < agronomy[i].size; j++)
		{
			sowingAreaSum += agronomy[i].agricultures[j].sowingArea;
		}
		if (sowingAreaSum < 55000)
		{
			printf("%s %f\n", agronomy[i].region, sowingAreaSum);
		}
	}

	// Task 2
	for (size_t i = 0; i < agrSize - 1; i++)
	{
		for (size_t j = 0; j < agrSize - i - 1; j++)
		{
			float cropVolumeSum1 = 0.0;
			float cropVolumeSum2 = 0.0;
			for (size_t s = 0; s < agronomy[j].size; s++)
			{
				cropVolumeSum1 += agronomy[j].agricultures[s].cropVolume;
			}
			for (size_t s = 0; s < agronomy[j + 1].size; s++)
			{
				cropVolumeSum2 += agronomy[j + 1].agricultures[s].cropVolume;
			}
			if (cropVolumeSum1 > cropVolumeSum2)
			{
				agronomyTemp = agronomy[j];
				agronomy[j] = agronomy[j + 1];
				agronomy[j + 1] = agronomyTemp;
			}
		}
	}

	for (size_t i = 0; i < agrSize; i++)
	{
		printf("%s\n", agronomy[i].region);
		for (size_t j = 0; j < agronomy[i].size; j++)
		{
			printf("\t%-15s%-15.4f%-10.4f\n", agronomy[i].agricultures[j].name,
				agronomy[i].agricultures[j].sowingArea, agronomy[i].agricultures[j].cropVolume);
		}
	}

	return 0;
}