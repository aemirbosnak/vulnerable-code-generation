//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

int main()
{
    int **grid = NULL;
    int x, y, z;
    int num_iter = 0;
    int seed = time(NULL);

    grid = malloc(DIM * sizeof(int *));
    for(x = 0; x < DIM; x++)
    {
        grid[x] = malloc(DIM * sizeof(int));
        for(y = 0; y < DIM; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Percolation
    for(z = 0; z < num_iter; z++)
    {
        for(x = 0; x < DIM; x++)
        {
            for(y = 0; y < DIM; y++)
            {
                if(grid[x][y] == 1)
                {
                    // Randomly flip neighboring cells
                    if(rand() % seed < 5)
                    {
                        grid[x][y] = 0;
                    }
                }
            }
        }
    }

    // Print the final grid
    for(x = 0; x < DIM; x++)
    {
        for(y = 0; y < DIM; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}