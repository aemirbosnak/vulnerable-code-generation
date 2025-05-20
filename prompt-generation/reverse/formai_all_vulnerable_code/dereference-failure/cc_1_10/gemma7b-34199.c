//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void drawGrid(int **grid, int rows, int cols)
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            printf("%c ", grid[r][c] == 0 ? '.' : '#');
        }
        printf("\n");
    }
}

int main()
{
    int rows = 10;
    int cols = 10;
    int **grid = (int**)malloc(rows * sizeof(int*));
    for(int r = 0; r < rows; r++)
    {
        grid[r] = (int*)malloc(cols * sizeof(int));
    }

    // Initial grid setup
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    // Game of Life simulation
    int generations = 0;
    while( generations < 10 )
    {
        drawGrid(grid, rows, cols);
        printf("Generation %d:\n", generations);

        // Calculate next generation
        int **nextGrid = (int**)malloc(rows * sizeof(int*));
        for(int r = 0; r < rows; r++)
        {
            nextGrid[r] = (int*)malloc(cols * sizeof(int));
        }

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if(r-1 >= 0) neighbors++;
                if(r+1 < rows) neighbors++;
                if(c-1 >= 0) neighbors++;
                if(c+1 < cols) neighbors++;

                nextGrid[r][c] = (neighbors == 3) ? 1 : 0;
            }
        }

        // Free the previous generation
        for(int r = 0; r < rows; r++)
        {
            free(grid[r]);
        }
        free(grid);

        // Swap grids
        int **tempGrid = grid;
        grid = nextGrid;
        nextGrid = tempGrid;

        generations++;
    }

    drawGrid(grid, rows, cols);
    printf("Final Grid:\n");

    // Free the grid
    for(int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}