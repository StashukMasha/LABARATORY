#include<stdio.h>
#include<math.h>

double InFunction(double x);
double CalcIntegral(double xStart, double xFinish, int region);

int main()
{
	double xStart, xFinish, E, result1,result2;
	int region = 1;
	printf("napishite predeli integrirovaniya: ");
	scanf_s("%lf%lf", &xStart, &xFinish);
	printf("Ukazhite pogreshnost E: ");
	scanf_s("%lf",&E);
	/*printf("Ukazhite kolichestvo regionov: ");
	scanf_s("%d", &region);*/
	
	result1 = CalcIntegral(xStart, xFinish, region);
	region *= 2;
	result2 = CalcIntegral(xStart, xFinish, region);
	
	while (fabs(result1 - result2) >= E)
	{
		result1 = result2;
		region *= 2;
		result2= CalcIntegral(xStart, xFinish, region);
	}
	printf("%f", result2);

	return 0;
}

double InFunction(double x) 
{
	return log(x);
}

double CalcIntegral(double xStart, double xFinish, int region) 
{
	double result = 0, step = (xFinish - xStart) / region;

	for (int i = 0; i < region; i++) {
		result += InFunction(xStart + step * (i + 0.5));
	}

	result *= step;
	return result;
}