//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 10
#define MAX_COL 10

int main()
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(MAX_ROW * sizeof(int *));
    for (int r = 0; r < MAX_ROW; r++)
    {
        grid[r] = (int *)malloc(MAX_COL * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < MAX_ROW; r++)
    {
        for (int c = 0; c < MAX_COL; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Simulate percolation
    int num_percolations = 0;
    for (int t = 0; t < 1000; t++)
    {
        // Randomly select two cells
        int row1 = rand() % MAX_ROW;
        int col1 = rand() % MAX_COL;
        int row2 = rand() % MAX_ROW;
        int col2 = rand() % MAX_COL;

        // If both cells are not occupied and they are adjacent, occupy them
        if (grid[row1][col1] == 0 && grid[row2][col2] == 0 && abs(row1 - row2) + abs(col1 - col2) <= 1)
        {
            grid[row1][col1] = grid[row2][col2] = 1;
            num_percolations++;
        }
    }

    // Print the number of percolations
    printf("Number of percolations: %d\n", num_percolations);

    // Free memory
    for (int r = 0; r < MAX_ROW; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}