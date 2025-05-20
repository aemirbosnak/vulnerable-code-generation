//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10

int main()
{
    int **grid = NULL;
    int **flood = NULL;
    int i, j, k, l, n;
    int x, y, r, s;
    time_t t;

    grid = (int **)malloc(DIM * sizeof(int *));
    flood = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
        flood[i] = (int *)malloc(DIM * sizeof(int));
    }

    srand(time(NULL));

    // Percolation
    for (k = 0; k < 1000; k++)
    {
        x = rand() % DIM;
        y = rand() % DIM;
        r = rand() % 2;

        if (r == 0)
        {
            grid[x][y] = 1;
        }
    }

    // Flood Fill
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            if (grid[i][j] == 1)
            {
                flood[i][j] = 1;
            }
        }
    }

    // Print
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", flood[i][j]);
        }
        printf("\n");
    }

    return 0;
}