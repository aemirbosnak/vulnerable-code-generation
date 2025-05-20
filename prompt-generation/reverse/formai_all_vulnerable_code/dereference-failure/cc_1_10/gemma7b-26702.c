//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawGrid(int **grid, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", grid[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = MAX;
    int **grid = (int **)malloc(size * sizeof(int *));
    for(int r = 0; r < size; r++)
    {
        grid[r] = (int *)malloc(size * sizeof(int));
    }

    // Initial grid setup
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[6][5] = 1;
    grid[6][6] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        drawGrid(grid, size);
        printf("Generation: %d\n", generation++);

        // Calculate next generation
        int **nextGrid = (int **)malloc(size * sizeof(int *));
        for(int r = 0; r < size; r++)
        {
            nextGrid[r] = (int *)malloc(size * sizeof(int));
        }

        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if(r - 1 >= 0) neighbors++;
                if(r + 1 < size) neighbors++;
                if(c - 1 >= 0) neighbors++;
                if(c + 1 < size) neighbors++;

                nextGrid[r][c] = (neighbors == 3) || (neighbors == 2 && grid[r][c] == 1);
            }
        }

        // Free the previous grid and copy the next generation
        for(int r = 0; r < size; r++)
        {
            free(grid[r]);
        }
        free(grid);

        grid = nextGrid;
        nextGrid = NULL;
    }

    return 0;
}