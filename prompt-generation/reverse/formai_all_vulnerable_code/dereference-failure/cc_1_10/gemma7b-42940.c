//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

void draw_grid(int **grid)
{
    for (int r = 0; r < GRID_SIZE; r++)
    {
        for (int c = 0; c < GRID_SIZE; c++)
        {
            printf("%c ", grid[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int r = 0; r < GRID_SIZE; r++)
    {
        grid[r] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    int ball_x = 2;
    int ball_y = 2;
    int direction = 1;

    grid[ball_x][ball_y] = 1;

    draw_grid(grid);

    while (!grid[ball_x][ball_y])
    {
        switch (direction)
        {
            case 1:
                ball_x++;
                break;
            case 2:
                ball_y++;
                break;
            case 3:
                ball_x--;
                break;
            case 4:
                ball_y--;
                break;
        }

        grid[ball_x][ball_y] = 1;

        draw_grid(grid);

        if (ball_x == 0 || ball_x == GRID_SIZE - 1)
            direction = (direction + 1) % 4;
        if (ball_y == 0 || ball_y == GRID_SIZE - 1)
            direction = (direction + 1) % 4;
    }

    free(grid);

    return 0;
}