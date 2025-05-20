//FormAI DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>

void matrix_addition(int rows, int columns, int mat1[][columns], int mat2[][columns])
{
    int result[rows][columns];
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("\nResult of Addition:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiplication(int rows1, int columns1, int rows2, int columns2, int mat1[][columns1], int mat2[][columns2])
{
    int i, j, k, result[rows1][columns2];
 
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < columns2; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < rows2; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("\nResult of Multiplication:\n");
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < columns2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows1, columns1, rows2, columns2, i, j;

    printf("Enter dimensions of matrix 1: ");
    scanf("%d%d", &rows1, &columns1);

    int mat1[rows1][columns1];

    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < columns1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter dimensions of matrix 2: ");
    scanf("%d%d", &rows2, &columns2);

    if (columns1 != rows2)
    {
        printf("Invalid dimensions! Cannot perform multiplication.\n");
        return 0;
    }

    int mat2[rows2][columns2];

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < rows2; i++)
    {
        for (j = 0; j < columns2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    matrix_addition(rows1, columns1, mat1, mat2);
    matrix_multiplication(rows1, columns1, rows2, columns2, mat1, mat2);

    return 0;
}