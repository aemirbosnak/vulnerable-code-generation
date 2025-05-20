//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int x, y, i, j, seed, water_level;

    seed = time(NULL);
    srand(seed);

    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    water_level = rand() % MAX_SIZE;

    for (x = 0; x < MAX_SIZE; x++)
    {
        for (y = 0; y < MAX_SIZE; y++)
        {
            grid[x][y] = rand() % 2;
        }
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (grid[i][j] == 1 && water_level > 0)
            {
                grid[i][j] = 2;
                water_level--;
            }
        }
    }

    for (x = 0; x < MAX_SIZE; x++)
    {
        for (y = 0; y < MAX_SIZE; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}