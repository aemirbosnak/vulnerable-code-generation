//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 20
#define HEIGHT 20

void drawGrid(int **grid)
{
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            printf("%c ", grid[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

void updateGrid(int **grid)
{
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            int neighbors = 0;
            if(grid[r-1][c] == '#') neighbors++;
            if(grid[r+1][c] == '#') neighbors++;
            if(grid[r][c-1] == '#') neighbors++;
            if(grid[r][c+1] == '#') neighbors++;

            if(grid[r][c] == '#' && neighbors < 2) grid[r][c] = '.';
            else if(grid[r][c] == '.' && neighbors == 3) grid[r][c] = '#';
        }
    }
}

int main()
{
    int **grid = (int**)malloc(HEIGHT * sizeof(int *));
    for(int r = 0; r < HEIGHT; r++) grid[r] = (int *)malloc(WIDTH * sizeof(int));

    // Initial grid setup
    grid[5][5] = grid[5][6] = grid[6][5] = grid[6][6] = '#';

    // Game loop
    for(int t = 0; t < 20; t++)
    {
        updateGrid(grid);
        drawGrid(grid);
    }

    // Free memory
    for(int r = 0; r < HEIGHT; r++) free(grid[r]);
    free(grid);

    return 0;
}