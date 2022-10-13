#include <stdio.h>
#include <math.h>

double function(double x)
{
	return 4 * pow(x, 4) - 70 * pow(x, 2) - 4 * x + 1;
}

double average(double start, double finish, double step)
{
	double sum = 0;
	int count = 0;
	for (double x = start; x <= finish; x += step)
	{
		sum += function(x);
		count++;
	}
	return sum / count;
}

int main()
{
	for (double x = -13.8; x <= 15; x += 1.8)
		printf("%-12.2f", x);
	printf("\n");
	for (double x = -13.8; x <= 15; x += 1.8)
		printf("%-12.2f", function(x));

	printf("\nAverage = %f", average(-13.8, 15, 1.8));

	return 0;
}