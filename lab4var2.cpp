#include <stdio.h>

const int n = 5;

void vvodMassiv(int arr[]);
void minPosition(int* min, int* position, int arr[]);
int countFunction(int min, int position, int arr[]);

int main()
{
	int arr[n];
	vvodMassiv(arr);
	int min = arr[0];
	int position = 0;
	minPosition(&min,&position,arr);
	printf("result:%d", countFunction(min,position,arr));

	return 0;
}

void vvodMassiv(int arr[])
{
	printf("vvedite massiv: ");

	for (int i=0;i<n;i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void minPosition(int* min, int* position, int arr[])
{
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < *min)
		{
			*min = arr[i];
			*position = i;
		}

	}
}

int countFunction(int min, int position, int arr[])
{
	int proizvedenie = 1;
	for (int i = 0; i < position; i++)
	{
		if (arr[i] < 2 * min)
		{
			proizvedenie *= arr[i];
		}
	}
	
	return proizvedenie;
}
