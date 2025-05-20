//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the percolating sand
    int **sand = (int **)malloc(DIM * sizeof(int *));
    for (int i = 0; i < DIM; i++)
    {
        sand[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize the sand
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            sand[i][j] = 0;
        }
    }

    // Percolate the sand
    int iterations = 0;
    while (!percolation(sand, DIM, DIM, iterations))
    {
        iterations++;
    }

    // Print the final sand
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", sand[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < DIM; i++)
    {
        free(sand[i]);
    }
    free(sand);

    return 0;
}

int percolation(int **sand, int dim, int dim2, int iterations)
{
    // Randomly choose a cell
    int x = rand() % dim;
    int y = rand() % dim2;

    // If the cell is not already saturated, and the sum of its neighbors is greater than the threshold,
    // saturate the cell and repeat the process
    if (sand[x][y] == 0 && sum(sand, x, y, dim, dim2) > 5)
    {
        sand[x][y] = 1;
        iterations++;
        return 0;
    }

    return 1;
}

int sum(int **sand, int x, int y, int dim, int dim2)
{
    int sum = 0;

    // Iterate over the neighboring cells
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            // If the neighbor cell is within the bounds of the array and has not been saturated,
            // add its value to the sum
            if (x + dx >= 0 && x + dx < dim && y + dy >= 0 && y + dy < dim2 && sand[x + dx][y + dy] == 1)
            {
                sum++;
            }
        }
    }

    return sum;
}