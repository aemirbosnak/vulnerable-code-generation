//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    int i, j, k;

    a = (int **)malloc(ROWS * sizeof(int *));
    b = (int **)malloc(ROWS * sizeof(int *));
    c = (int **)malloc(ROWS * sizeof(int *));

    for (i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
        b[i] = (int *)malloc(COLS * sizeof(int));
        c[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Matrix A
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;

    // Matrix B
    b[0][0] = 10;
    b[0][1] = 11;
    b[0][2] = 12;
    b[1][0] = 13;
    b[1][1] = 14;
    b[1][2] = 15;
    b[2][0] = 16;
    b[2][1] = 17;
    b[2][2] = 18;

    // Matrix C (Result)
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < ROWS; k++)
            {
                c[i][j] += a[k][j] * b[k][i];
            }
        }
    }

    // Print Matrix C
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            free(a[i][j]);
            free(b[i][j]);
            free(c[i][j]);
        }
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}