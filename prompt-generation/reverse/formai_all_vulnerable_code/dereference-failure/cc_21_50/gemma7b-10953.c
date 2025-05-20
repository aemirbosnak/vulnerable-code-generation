//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

int main()
{
    int **grid = NULL;
    int **percolation_array = NULL;
    int size = MAX_SIZE;
    int i, j, k;
    int seed = time(NULL);

    // Allocate memory for the grid and percolation array
    grid = (int **)malloc(size * sizeof(int *));
    percolation_array = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
        percolation_array[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid and percolation array
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
            percolation_array[i][j] = 0;
        }
    }

    // Randomly assign some sites to be occupied
    for (k = 0; k < 100; k++)
    {
        i = rand() % size;
        j = rand() % size;
        grid[i][j] = 1;
    }

    // Percolation algorithm
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (grid[i][j] == 1)
            {
                percolation_array[i][j] = 1;
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    percolation_array[i - 1][j] = 1;
                }
                if (i < size - 1 && grid[i + 1][j] == 1)
                {
                    percolation_array[i + 1][j] = 1;
                }
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    percolation_array[i][j - 1] = 1;
                }
                if (j < size - 1 && grid[i][j + 1] == 1)
                {
                    percolation_array[i][j + 1] = 1;
                }
            }
        }
    }

    // Print the percolating sites
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (percolation_array[i][j] == 1)
            {
                printf("%d %d\n", i, j);
            }
        }
    }

    // Free the memory
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            free(grid[i][j]);
            free(percolation_array[i][j]);
        }
        free(grid[i]);
        free(percolation_array[i]);
    }
    free(grid);
    free(percolation_array);

    return 0;
}