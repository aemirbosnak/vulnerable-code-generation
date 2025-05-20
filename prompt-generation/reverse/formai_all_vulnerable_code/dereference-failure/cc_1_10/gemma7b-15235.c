//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int x, y;

    // Allocate memory for the grid
    grid = (int**)malloc(size * sizeof(int*));
    for (x = 0; x < size; x++)
    {
        grid[x] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Percolation simulation
    time_t start = time(NULL);
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (grid[x][y] == 0)
            {
                int rand_num = rand() % 2;
                if (rand_num == 0)
                {
                    grid[x][y] = 1;
                }
            }
        }
    }

    time_t end = time(NULL);
    int time_taken = end - start;

    // Print the results
    printf("Time taken: %d seconds\n", time_taken);
    printf("Number of saturated cells: %d\n", count_saturated_cells(grid, size));

    // Free the memory
    for (x = 0; x < size; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}

int count_saturated_cells(int **grid, int size)
{
    int x, y;
    int count = 0;

    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (grid[x][y] == 1)
            {
                count++;
            }
        }
    }

    return count;
}