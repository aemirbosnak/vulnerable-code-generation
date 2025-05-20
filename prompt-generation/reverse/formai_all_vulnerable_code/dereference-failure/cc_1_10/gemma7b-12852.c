//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

int main()
{
    int **arr = NULL;
    int i, j, k, l, r, c, x, y;
    int seed = time(NULL);

    arr = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            arr[i][j] = 0;
        }
    }

    srand(seed);

    for (k = 0; k < 100; k++)
    {
        x = rand() % DIM;
        y = rand() % DIM;

        if (arr[x][y] == 0)
        {
            arr[x][y] = 1;
        }
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}