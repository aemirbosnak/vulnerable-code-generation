//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void matrix_operations(int ***matrix, int r, int c)
{
    int i, j, k;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            for (k = 0; k < c; k++)
            {
                if (k == j)
                {
                    (*matrix)[i][j] = 1;
                }
                else
                {
                    (*matrix)[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    int **matrix = NULL;
    int r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    matrix = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
    {
        matrix[i] = (int *)malloc(c * sizeof(int));
    }

    matrix_operations(&matrix, r, c);

    printf("The matrix after operations:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}