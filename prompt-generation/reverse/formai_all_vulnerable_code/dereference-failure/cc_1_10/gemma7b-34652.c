//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void MatrixOperations(int **arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Element at (%d, %d) is: %d\n", i, j, arr[i][j]);
        }
    }

    printf("\n");
    printf("Transposing the matrix...\n");

    int **transposed = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++)
    {
        transposed[i] = (int *)malloc(sizeof(int) * c);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            transposed[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Element at (%d, %d) in the transposed matrix is: %d\n", i, j, transposed[i][j]);
        }
    }

    free(transposed);
}

int main()
{
    int **arr = (int **)malloc(sizeof(int *) * ROWS);
    for (int i = 0; i < ROWS; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * COLS);
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[1][0] = 50;
    arr[1][1] = 60;
    arr[1][2] = 70;
    arr[1][3] = 80;
    arr[2][0] = 90;
    arr[2][1] = 100;
    arr[2][2] = 110;
    arr[2][3] = 120;

    MatrixOperations(arr, ROWS, COLS);

    free(arr);

    return 0;
}