//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the seed for random number generation
    srand(time(NULL));

    // Create a 2D array to simulate the percolating fluid
    int** grid = NULL;
    grid = malloc(10 * sizeof(int*));
    for(int i = 0; i < 10; i++)
    {
        grid[i] = malloc(10 * sizeof(int));
    }

    // Initialize the grid with random values
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate the percolating fluid
    int iterations = 0;
    while(!percolation(grid, 10, 10))
    {
        iterations++;
    }

    // Print the number of iterations it took for the fluid to percolate
    printf("Number of iterations: %d\n", iterations);

    // Free the memory allocated for the grid
    for(int i = 0; i < 10; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int percolation(int** grid, int rows, int cols)
{
    // Check if the fluid has percolated
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 1)
            {
                return 0;
            }
        }
    }

    return 1;
}