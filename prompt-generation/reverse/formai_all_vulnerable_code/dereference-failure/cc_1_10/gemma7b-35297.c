//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40

void draw_grid(int **grid)
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

int main()
{
    int **grid = malloc(HEIGHT * sizeof(int *));
    for(int r = 0; r < HEIGHT; r++)
    {
        grid[r] = malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Place the invader
    grid[0][10] = 1;

    draw_grid(grid);

    // Move the invader
    grid[0][10] = 0;
    grid[0][11] = 1;

    draw_grid(grid);

    free(grid);
    return 0;
}