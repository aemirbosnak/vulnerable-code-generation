//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, m, x, y;
    char **grid = NULL;
    time_t t = time(NULL);

    // Allocate memory for the grid
    grid = (char **)malloc(n * sizeof(char *) + 1);
    for (i = 0; i < n; i++)
    {
        grid[i] = (char *)malloc(m * sizeof(char) + 1);
    }

    // Initialize the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            grid[i][j] = ' ';
        }
    }

    // Create the weather pattern
    x = rand() % n;
    y = rand() % m;
    grid[x][y] = 'W';

    // Simulate the weather
    for (i = 0; i < t; i++)
    {
        x = rand() % n;
        y = rand() % m;
        if (grid[x][y] == 'W')
        {
            grid[x][y] = 'O';
        }
    }

    // Print the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}