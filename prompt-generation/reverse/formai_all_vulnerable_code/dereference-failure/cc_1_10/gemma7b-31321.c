//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void game_of_life(int **grid)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            int neighbors = 0;
            if (r > 0) neighbors++;
            if (r < MAX_SIZE - 1) neighbors++;
            if (c > 0) neighbors++;
            if (c < MAX_SIZE - 1) neighbors++;

            if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
            if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
        }
    }
}

int main()
{
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        grid[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;

    game_of_life(grid);

    // Print the grid
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}