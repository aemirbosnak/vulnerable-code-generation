//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set some random cells to 1
    grid[5][5] = 1;
    grid[4][4] = 1;
    grid[3][3] = 1;

    // Simulate the game of life
    for(int t = 0; t < 20; t++)
    {
        // Calculate the number of neighbors for each cell
        for(int i = 0; i < MAX_SIZE; i++)
        {
            for(int j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                if(grid[i-1][j] == 1) neighbors++;
                if(grid[i+1][j] == 1) neighbors++;
                if(grid[i][j-1] == 1) neighbors++;
                if(grid[i][j+1] == 1) neighbors++;
                if(grid[i-1][j-1] == 1) neighbors++;
                if(grid[i-1][j+1] == 1) neighbors++;
                if(grid[i+1][j-1] == 1) neighbors++;
                if(grid[i+1][j+1] == 1) neighbors++;

                // Apply the rules of life
                if(grid[i][j] == 1 && neighbors < 2) grid[i][j] = 0;
                if(grid[i][j] == 0 && neighbors == 3) grid[i][j] = 1;
            }
        }
    }

    // Print the final grid
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}