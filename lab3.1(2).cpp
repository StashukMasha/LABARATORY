#include <stdio.h>
#include <math.h>


double function(double,double);

int main()
{
	double E, znam, sum, resultpast, resultcurrent;
	printf("Enter E: ");
	scanf_s("%lf", &E);
	znam = 1;
	resultcurrent = function(znam, 1);
	sum=resultcurrent;
	znam = 2;
	do
	{
		resultpast = resultcurrent;
		resultcurrent = function(znam, resultpast);
		sum += resultcurrent;
		znam = znam + 1;
	} while (resultcurrent > E);
	printf("Answer: %lf", sum);
}

double function(double znam, double resultpast)
{
	return resultpast / znam;
}