//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **grid;
    int size = MAX_SIZE;
    int num_occupied = 0;
    int threshold = 50;

    // Allocate memory for the grid
    grid = (int *)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++)
    {
        grid[i] = 0;
    }

    // Randomly select a set of sites to be occupied
    srand(time(NULL));
    for (int i = 0; i < threshold; i++)
    {
        int row = rand() % size;
        int col = rand() % size;
        if (grid[row * size + col] == 0)
        {
            grid[row * size + col] = 1;
            num_occupied++;
        }
    }

    // Spread water from the occupied sites to the empty neighboring sites
    for (int i = 0; i < size * size; i++)
    {
        if (grid[i] == 1)
        {
            int row = i / size;
            int col = i % size;
            int neighbors[4] = {row - 1, row + 1, col - 1, col + 1};
            for (int j = 0; j < 4; j++)
            {
                if (neighbors[j] >= 0 && neighbors[j] < size && grid[neighbors[j]] == 0)
                {
                    grid[neighbors[j]] = 1;
                    num_occupied++;
                }
            }
        }
    }

    // Print the number of occupied sites
    printf("Number of occupied sites: %d\n", num_occupied);

    // Free memory
    free(grid);

    return 0;
}