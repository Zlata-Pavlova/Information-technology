#include <stdio.h>
#include <math.h>

int main()
{
	int count = 0;
	double sum = 0, f;
	for (double x = -13.8; x <= 15; x += 1.8)
		printf("%-12.2f", x);
	printf("\n");
	for (double x = -13.8; x <= 15; x += 1.8)
	{
		f = (4 * pow(x, 4) - 70 * pow(x, 2) - 4 * x + 1);
		sum += f;
		count++;
		printf("%-12.2f", f);
	}
	printf("\nAverage = %f", sum / count);

	return 0;
}