#include<stdio.h>
#include<malloc.h>

int main()
{
	int st, str;
	printf("vvedite stolbes i stroku: ");
	scanf_s("%d%d", &st, &str);
	int** matrix;
	matrix = (int**)malloc(st * sizeof(int*));
	for (int i = 0; i < str; i++)
		matrix[i] = (int*)malloc(st * sizeof(int));
	printf("vvedite massiv stolb*str: ");
	for (int i = 0; i < str; i++)
		for (int j = 0; j < st; j++)
			scanf_s("%d", &matrix[i][j]);
	int sum = 0;
	for (int j = 0; j < st; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < str; i++)
			{
				printf("%d ", matrix[i][j]);
			}
		}
		else
		{
			for (int i = str; i >= 0; i--)
			{
				printf("%d ", matrix[i][j]);
			}
		}
	}
	for (int i = 0; i < str; i++)
		free(matrix[i]);
	free(matrix);

	return 0;
}