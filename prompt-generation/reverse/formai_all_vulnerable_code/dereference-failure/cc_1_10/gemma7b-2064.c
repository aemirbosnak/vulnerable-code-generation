//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main()
{
    int **a = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        a[i] = (int *)malloc(COLS * sizeof(int));
    }

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[0][3] = 4;
    a[1][0] = 5;
    a[1][1] = 6;
    a[1][2] = 7;
    a[1][3] = 8;
    a[2][0] = 9;
    a[2][1] = 10;
    a[2][2] = 11;
    a[2][3] = 12;

    int **b = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        b[i] = (int *)malloc(COLS * sizeof(int));
    }

    b[0][0] = 3;
    b[0][1] = 2;
    b[0][2] = 4;
    b[0][3] = 1;
    b[1][0] = 6;
    b[1][1] = 5;
    b[1][2] = 7;
    b[1][3] = 2;
    b[2][0] = 9;
    b[2][1] = 8;
    b[2][2] = 10;
    b[2][3] = 3;

    int **c = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        c[i] = (int *)malloc(COLS * sizeof(int));
    }

    c[0][0] = 4;
    c[0][1] = 3;
    c[0][2] = 2;
    c[0][3] = 1;
    c[1][0] = 7;
    c[1][1] = 6;
    c[1][2] = 5;
    c[1][3] = 2;
    c[2][0] = 10;
    c[2][1] = 9;
    c[2][2] = 8;
    c[2][3] = 3;

    int **d = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        d[i] = (int *)malloc(COLS * sizeof(int));
    }

    d[0][0] = 1;
    d[0][1] = 2;
    d[0][2] = 3;
    d[0][3] = 4;
    d[1][0] = 5;
    d[1][1] = 6;
    d[1][2] = 7;
    d[1][3] = 8;
    d[2][0] = 9;
    d[2][1] = 10;
    d[2][2] = 11;
    d[2][3] = 12;

    int result = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            result = a[i][j] + b[i][j] - c[i][j] + d[i][j];
            printf("%d ", result);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}