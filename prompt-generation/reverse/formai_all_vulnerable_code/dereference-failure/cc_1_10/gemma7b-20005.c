//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void MatrixOperations(int ***matrix)
{
    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            for (k = 0; k < ROWS; k++)
            {
                if (i == k)
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
    int i, j;

    matrix = (int ***)malloc(ROWS * sizeof(int **));

    for (i = 0; i < ROWS; i++)
    {
        matrix[i] = (int *)malloc(COLS * sizeof(int));
    }

    MatrixOperations(&matrix);

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    free(matrix);

    return 0;
}