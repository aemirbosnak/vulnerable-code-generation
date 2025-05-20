//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_grid(int **grid)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", grid[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        grid[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initial grid setup
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    int generations = 0;
    while (1)
    {
        draw_grid(grid);
        printf("Generation: %d\n", generations);

        // Calculate next generation
        int **next_grid = (int **)malloc(MAX_SIZE * sizeof(int *));
        for (int r = 0; r < MAX_SIZE; r++)
        {
            next_grid[r] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < MAX_SIZE - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < MAX_SIZE - 1) neighbors++;

                next_grid[r][c] = (neighbors == 3) || (neighbors == 2 && grid[r][c] == 1);
            }
        }

        free(grid);
        grid = next_grid;
        generations++;

        // Break condition
        if (grid[0][0] == 0) break;
    }

    return 0;
}