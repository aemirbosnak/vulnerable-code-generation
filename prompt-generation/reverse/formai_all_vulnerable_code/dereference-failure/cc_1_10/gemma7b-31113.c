//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int i, j, k, r, c;

    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation simulation
    for(k = 0; k < 10; k++)
    {
        // Randomly select a row and column
        r = rand() % MAX_SIZE;
        c = rand() % MAX_SIZE;

        // If the cell is not already wet and the sum of its neighbors is greater than the threshold,
        // then make the cell wet
        if(grid[r][c] == 0 && (grid[r-1][c] + grid[r+1][c] + grid[r][c-1] + grid[r][c+1] > MAX_SIZE / 2))
        {
            grid[r][c] = 1;
        }
    }

    // Print the wet cells
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}