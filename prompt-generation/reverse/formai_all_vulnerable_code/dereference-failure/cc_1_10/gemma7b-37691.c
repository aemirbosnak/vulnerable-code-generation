//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10
#define MAX_WATER 100

int main()
{
    int **grid = NULL;
    int i, j, water = MAX_WATER, round = 0;
    char msg[200];

    grid = (int**)malloc(DIM * sizeof(int*));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int*)malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));

    // Percolation Simulation
    while (water > 0)
    {
        round++;
        water--;

        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 0 && rand() % 2 == 0)
                {
                    grid[i][j] = 1;
                    water++;
                }
            }
        }

        sprintf(msg, "Round %d, Water Left: %d", round, water);
        printf("%s\n", msg);
    }

    free(grid);

    return 0;
}