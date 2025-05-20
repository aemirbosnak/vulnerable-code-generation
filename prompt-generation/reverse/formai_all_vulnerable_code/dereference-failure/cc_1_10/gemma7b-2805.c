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

    b[0][0] = 13;
    b[0][1] = 14;
    b[0][2] = 15;
    b[0][3] = 16;
    b[1][0] = 17;
    b[1][1] = 18;
    b[1][2] = 19;
    b[1][3] = 20;
    b[2][0] = 21;
    b[2][1] = 22;
    b[2][2] = 23;
    b[2][3] = 24;

    int **c = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        c[i] = (int *)malloc(COLS * sizeof(int));
    }

    c[0][0] = a[0][0] + b[0][0];
    c[0][1] = a[0][1] + b[0][1];
    c[0][2] = a[0][2] + b[0][2];
    c[0][3] = a[0][3] + b[0][3];
    c[1][0] = a[1][0] + b[1][0];
    c[1][1] = a[1][1] + b[1][1];
    c[1][2] = a[1][2] + b[1][2];
    c[1][3] = a[1][3] + b[1][3];
    c[2][0] = a[2][0] + b[2][0];
    c[2][1] = a[2][1] + b[2][1];
    c[2][2] = a[2][2] + b[2][2];
    c[2][3] = a[2][3] + b[2][3];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}