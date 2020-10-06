#include <stdio.h>

#define ARRAY_SIZE 5

void InputArray(int arr[]);
int getMinArrayIndex(int arr[]);
int getMultiply(int arr[]);

int main()
{
	int arr[ARRAY_SIZE];

	InputArray(arr);
	getMinArrayIndex(arr);
	printf("result:%d", getMultiply(arr));

	return 0;
}

void InputArray(int arr[])
{
	printf("vvedite massiv: ");

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int getMinArrayIndex(int arr[])
{
	int minIndex = 0;
	int min = arr[minIndex];
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minIndex = i;
		}

	}
	return minIndex;
}

int getMultiply(int arr[])
{
	int min = arr[getMinArrayIndex(arr)];
	int multiply = 1;
	for (int i = 0; i < getMinArrayIndex(arr); i++)
	{
		if (arr[i] < 2 * min)
		{
			multiply *= arr[i];
		}
	}

	return multiply;
}
