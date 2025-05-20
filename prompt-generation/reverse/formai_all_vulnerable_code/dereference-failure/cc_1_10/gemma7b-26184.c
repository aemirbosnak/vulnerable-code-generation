//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **grid, int rows, int cols)
{
    int i, j, r, c, live_neighbors;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            live_neighbors = 0;
            r = i - 1;
            c = j - 1;
            while (r <= i + 1 && r >= 0)
            {
                while (c <= j + 1 && c >= 0)
                {
                    if (grid[r][c] == 1)
                    {
                        live_neighbors++;
                    }
                    c++;
                }
                r++;
            }
            if (grid[i][j] == 1 && live_neighbors < 2)
            {
                grid[i][j] = 0;
            }
            else if (grid[i][j] == 0 && live_neighbors == 3)
            {
                grid[i][j] = 1;
            }
        }
    }
}

int main()
{
    int rows = 5, cols = 5;
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    grid[1][1] = grid[2][2] = grid[2][3] = grid[3][2] = 1;

    GameOfLife(grid, rows, cols);

    // Print the updated grid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);
    return 0;
}