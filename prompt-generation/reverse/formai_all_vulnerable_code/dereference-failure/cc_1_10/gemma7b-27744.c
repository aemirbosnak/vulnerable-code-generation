//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 256

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a grid of squares
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolate the squares
    int num_percolation = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (grid[i][j] == 0)
            {
                int rand_num = rand() % 2;
                if (rand_num == 0)
                {
                    grid[i][j] = 1;
                    num_percolation++;
                }
            }
        }
    }

    // Print the number of percolated squares
    printf("Number of percolated squares: %d\n", num_percolation);

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}