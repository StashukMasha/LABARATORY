#include <stdio.h>
#include <math.h>

double function(double znamenatel);

int main()
{
	double E, sum = 0, znamenatel = 1, schetchikznam = 1;

	printf("Vvedite tochnost E: ");
	scanf_s("%lf", &E);
	function(znamenatel);
	double drob = function(znamenatel);
	while (drob > E)
	{
		sum += drob;
		schetchikznam++;
		znamenatel *= schetchikznam;
		drob = 1 / znamenatel;
	}
	printf("%f", sum);
	return 0;
}

double function(double znamenatel)
{
	return 1 / znamenatel;
}