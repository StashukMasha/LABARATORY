#include<malloc.h>
#include<stdio.h>

int** allocateMatrix(int row, int col);
void inputMatrix(int** matrix, int row, int col);
void outputOriginalMatrix(int** matrix, int row, int col);
int* allocateArr(int row, int col);
void transportationMatrixInArr(int** matrix, int* arr, int row, int col, int* index);
void sortBubble(int* arr, int row, int col, int* index);
void transportationArrInMatrix(int** matrix, int* arr, int row, int col);
void sortVerticalSnake(int** matrix, int row, int col);
void outputMatrix(int** matrix, int row, int col);
void freeingMemory(int** matrix, int row);

int main()
{
    int** matrix, row, col;
    int* arr;

    printf("row&col= ");
    scanf_s("%d%d", &row, &col);

    matrix = allocateMatrix(row, col);
   
    inputMatrix(matrix, row, col);

    outputOriginalMatrix(matrix, row, col);
    
    arr = allocateArr(row, col);
   
    int index = 0;

    transportationMatrixInArr(matrix, arr, row, col, &index);

    sortBubble(arr, row, col, &index);

    transportationArrInMatrix(matrix, arr, row, col);

    sortVerticalSnake(matrix, row, col);

    outputMatrix(matrix, row, col);

    freeingMemory(matrix, row);

	return 0;
}


int** allocateMatrix(int row, int col)
{
    int** matrix = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }
    return matrix;
}


void inputMatrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]= ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }
}


void outputOriginalMatrix(int** matrix, int row, int col)
{
    printf("original matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}


int* allocateArr(int row, int col)
{
    int* arr = (int*)malloc(row * col * sizeof(int));
    return arr;
}


void transportationMatrixInArr(int** matrix, int* arr, int row, int col, int* index)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            arr[*index] = matrix[i][j];
            *index = *index + 1;

        }
    }
}


void sortBubble(int* arr, int row, int col, int* index)
{
    for (int j = 0; j < *index; j++)
    {
        for (int i = 0; i < *index - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}


void transportationArrInMatrix(int** matrix, int* arr, int row, int col)
{
    int index = 0;
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][j] = arr[index++];
        }
    }
    printf("\n");
}


void sortVerticalSnake(int** matrix, int row, int col)
{
    for (int i = 0; i < row / 2; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j % 2 != 0)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[row - 1 - i][j];
                matrix[row - 1 - i][j] = tmp;
            }
        }
    }
}


void outputMatrix(int** matrix, int row, int col)
{
    printf("Vertical snake:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}


void freeingMemory(int** matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
