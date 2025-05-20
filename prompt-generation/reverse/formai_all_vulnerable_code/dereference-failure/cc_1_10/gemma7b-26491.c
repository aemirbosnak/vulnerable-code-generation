//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void mx_operations(int **a, int **b)
{
    int i, j, k;
    int r = ROWS;
    int c = COLS;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            b[i][j] = 0;
            for (k = 0; k < r; k++)
            {
                if (a[k][j] > 0)
                {
                    b[i][j] += a[k][j];
                }
            }
        }
    }
}

int main()
{
    int **a = NULL;
    int **b = NULL;

    a = (int **)malloc(ROWS * sizeof(int *));
    b = (int **)malloc(ROWS * sizeof(int *));

    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
        b[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Sample data
    a[0][0] = 10;
    a[0][1] = 20;
    a[1][0] = 30;
    a[1][1] = 40;

    mx_operations(a, b);

    // Print the result
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}