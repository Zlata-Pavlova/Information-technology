#include <stdio.h>
#include <math.h>

// TODO: Спросить у препода про возвращение двух корней.
double calculation(double a, double b, double c)
{
	if (a == 0 || b == 0)
		return 0;
	else
		return (-b + sqrt((b * b) - (4 * a * c) / b)) / 2 * a;
}

int main()
{
	printf("%lf", calculation(5, 7, 6));
	return 0;
}