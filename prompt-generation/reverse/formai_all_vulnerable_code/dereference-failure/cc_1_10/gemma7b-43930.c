//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20
#define MAX_WATER 10

int main()
{
    int **grid = NULL;
    int water_level = MAX_WATER;
    int x, y;
    int num_percolation = 0;

    grid = (int**)malloc(DIM * sizeof(int*));
    for (x = 0; x < DIM; x++)
    {
        grid[x] = (int*)malloc(DIM * sizeof(int));
    }

    for (x = 0; x < DIM; x++)
    {
        for (y = 0; y < DIM; y++)
        {
            grid[x][y] = 0;
        }
    }

    srand(time(NULL));

    for (x = 0; x < MAX_WATER; x++)
    {
        int r = rand() % DIM;
        int c = rand() % DIM;
        if (grid[r][c] == 0)
        {
            grid[r][c] = 1;
            num_percolation++;
        }
    }

    printf("Number of percolations: %d\n", num_percolation);

    for (x = 0; x < DIM; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}