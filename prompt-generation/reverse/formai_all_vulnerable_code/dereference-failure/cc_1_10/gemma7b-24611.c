//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

int main()
{
    int **grid = NULL;
    int i, j, x, y, num_percolation = 0;

    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    srand(time(NULL));

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            if (grid[i][j] == 1)
            {
                num_percolation++;
                x = i;
                y = j;
            }
        }
    }

    printf("Number of percolations: %d\n", num_percolation);
    printf("Percolation location: (%d, %d)\n", x, y);

    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}