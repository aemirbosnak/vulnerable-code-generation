//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void matrix_operations(int **a, int **b)
{
    int i, j, k;
    int **c = (int *)malloc(ROWS * COLS * sizeof(int));

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                if (a[i][k] && b[k][j])
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }

    printf("The product of the two matrices is:\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(c);
}

int main()
{
    int **a = (int *)malloc(ROWS * COLS * sizeof(int));
    int **b = (int *)malloc(ROWS * COLS * sizeof(int));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    matrix_operations(a, b);

    free(a);
    free(b);

    return 0;
}