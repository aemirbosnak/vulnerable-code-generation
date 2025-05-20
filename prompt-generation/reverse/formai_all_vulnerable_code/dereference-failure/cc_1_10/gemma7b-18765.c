//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, y, w, h, min_x, min_y, max_x, max_y;
    char **grid;

    // Allocate memory for the grid
    w = 10;
    h = 10;
    grid = (char **)malloc(h * sizeof(char *) + w * sizeof(char));
    for (i = 0; i < h; i++)
    {
        grid[i] = (char *)malloc(w * sizeof(char));
    }

    // Initialize the grid
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            grid[i][j] = '.';
        }
    }

    // Simulate weather patterns
    min_x = 2;
    min_y = 3;
    max_x = 5;
    max_y = 6;
    for (x = min_x; x <= max_x; x++)
    {
        for (y = min_y; y <= max_y; y++)
        {
            grid[y][x] = 'H';
        }
    }

    // Print the grid
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < h; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}