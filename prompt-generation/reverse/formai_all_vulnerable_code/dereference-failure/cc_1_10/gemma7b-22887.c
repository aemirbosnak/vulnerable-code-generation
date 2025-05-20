//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int iterations = 0;
    int seed = time(NULL);

    grid = (int **)malloc(size * sizeof(int *) * size);
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    while (!Percolation(grid, size, iterations))
    {
        iterations++;
    }

    printf("Number of iterations: %d\n", iterations);

    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int Percolation(int **grid, int size, int iterations)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j] == 0)
            {
                int count = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (grid[i + x][j + y] == 1)
                        {
                            count++;
                        }
                    }
                }

                if (count > 0)
                {
                    grid[i][j] = 1;
                }
            }
        }
    }

    return 1;
}