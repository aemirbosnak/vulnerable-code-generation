//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: active
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
    int **grid = NULL;
    int rows = 5;
    int cols = 5;

    grid = (int**)malloc(rows * sizeof(int*));
    for(int r = 0; r < rows; r++)
    {
        grid[r] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Simulate game of life
    for(int t = 0; t < 10; t++)
    {
        drawGrid(grid, rows, cols);

        // Calculate the next generation
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if(r > 0) neighbors++;
                if(r < rows - 1) neighbors++;
                if(c > 0) neighbors++;
                if(c < cols - 1) neighbors++;

                if(grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
                if(grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            }
        }
    }

    drawGrid(grid, rows, cols);

    // Free the memory
    for(int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}