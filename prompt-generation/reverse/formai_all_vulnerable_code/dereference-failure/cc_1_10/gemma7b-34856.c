//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void GameOfLife(int **grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            if (grid[i][j] == 1 && neighbors < 2) grid[i][j] = 0;
            if (grid[i][j] == 0 && neighbors == 3) grid[i][j] = 1;
        }
    }
}

int main()
{
    int size = MAX;
    int **grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) grid[i] = (int*)malloc(size * sizeof(int));

    // Initialize the grid
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[2][2] = 1;

    // Game of Life
    GameOfLife(grid, size);

    // Print the grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++) free(grid[i]);
    free(grid);

    return 0;
}