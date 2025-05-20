//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawGrid(int **grid, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **grid = NULL;
    int x = 5;
    int y = 5;

    grid = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++)
    {
        grid[i] = (int*)malloc(y * sizeof(int));
    }

    // Game of Life Rules
    grid[2][2] = 1;
    grid[2][3] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
    grid[4][2] = 1;

    // Simulate 5 generations
    for (int gen = 0; gen < 5; gen++)
    {
        drawGrid(grid, x, y);

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                int neighbors = 0;
                if (grid[i-1][j] == 1) neighbors++;
                if (grid[i+1][j] == 1) neighbors++;
                if (grid[i][j-1] == 1) neighbors++;
                if (grid[i][j+1] == 1) neighbors++;

                if (grid[i][j] == 1 && neighbors < 2) grid[i][j] = 0;
                if (grid[i][j] == 0 && neighbors == 3) grid[i][j] = 1;
            }
        }
    }

    drawGrid(grid, x, y);

    free(grid);

    return 0;
}