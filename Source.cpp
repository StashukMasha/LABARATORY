#include<stdio.h>
#include <malloc.h>

int inputArray(int *arr,int sizeArray);
void sortingPuziric(int* arr, int sizeArray);
void outputArray(int* arr, int sizeArray);


int main()
{
	int sizeArray;

	printf("print size of array: ");
	scanf_s("%d", &sizeArray);

	int* arr = (int*)malloc(sizeArray * sizeof(int));

	
	inputArray(arr, sizeArray);

	sortingPuziric(arr, sizeArray);

	outputArray(arr, sizeArray);

	free(arr);
	
	return 0;
}

int inputArray(int* arr, int sizeArray)
{
	int i;

	for (i = 0; i < sizeArray; i++)
	{
		printf("print array: ");
		scanf_s("%d ", &arr[i]);
	}
	return *arr;
}

void sortingPuziric(int* arr, int sizeArray)
{
	
	int i, j;
	for (j = 0; j < sizeArray; j++)
	{
			for ( i = 0; i < sizeArray-j-1 ; i++)
			{
				if (arr[i] < 0 && arr[i + 1] < 0)
				{
					if (arr[i] > arr[i + 1])
					{
						int tmp = arr[i];
						arr[i] = arr[i + 1];
						arr[i + 1] = tmp;
					}

				}
				else if (arr[i] < arr[i + 1])
				{
					int tmp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = tmp;
				}
			}
	}
}

void outputArray(int* arr, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		printf("%d ", arr[i]);

	}
}
	
