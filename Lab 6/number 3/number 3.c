#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 256

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
	Agriculture agricultures[10];
};

typedef struct _Agronomy Agronomy;

int main()
{
	Agronomy agronomy[3] = { 0 };
	FILE* in = fopen("agronomy.txt", "r");
	int index = 0;
	char line[1024];
	char* ptr;
	int i, contains;

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
				index = 0;
				contains = 0;
				for (size_t r = 0; r < 3; r++)
				{
					if (strcmp(ptr, agronomy[r].region) == 0)
					{
						index = r;
						contains = 1;
						break;
					}
					if (strcmp(ptr, agronomy[r].region) != 0 && strlen(agronomy[r].region) == 0)
					{
						index++;
					}
				}
				if (!contains)
				{
					strcpy(agronomy[index].region, ptr);
					agronomy[index].size = 0;
				}
				break;
			case 1:
				strcpy(agronomy[index].agricultures[agronomy[index].size].name, ptr);
				break;
			case 2:
				sscanf(ptr, "%f", &agronomy[index].agricultures[agronomy[index].size].cropVolume);
				break;
			case 3:
				sscanf(ptr, "%f", &agronomy[index].agricultures[agronomy[index].size].sowingArea);
				agronomy[index].size++;
				break;
			}
			i++;
			ptr = strtok(NULL, ",");
		}
	}


	return 0;
}