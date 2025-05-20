//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

void Matrix_Operations(int **arr, int r, int c)
{
    int i, j, k;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (k = 0; k < r; k++)
    {
        free(arr[k]);
    }
    free(arr);
}

int main()
{
    int **arr = NULL;

    arr = (int **)malloc(ROW * sizeof(int *));

    for (int i = 0; i < ROW; i++)
    {
        arr[i] = (int *)malloc(COL * sizeof(int));
    }

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[0][3] = 4;

    arr[1][0] = 5;
    arr[1][1] = 6;
    arr[1][2] = 7;
    arr[1][3] = 8;

    arr[2][0] = 9;
    arr[2][1] = 10;
    arr[2][2] = 11;
    arr[2][3] = 12;

    Matrix_Operations(arr, ROW, COL);

    return 0;
}