#include <stdio.h>

const int n = 5;
int arr[n];

int proizvedenie = 1;
int main()
{
	printf("vvedite massiv: ");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
		int min = arr[0];
		int position = 0;
		for (int i = 1; i < n; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				position = i;
			}

		}
		for (int i = 0; i < position; i++)
		{
			if (arr[i] < 2 * min)
			{
				proizvedenie *= arr[i];
			}

		}
	}

	printf("result: %d", proizvedenie);


	return 0;

}