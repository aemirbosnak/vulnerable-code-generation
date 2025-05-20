//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

int main()
{
    int x, y, i, j, r, c;
    char **grid = NULL;

    // Allocate memory for the grid
    grid = (char**)malloc(MAX_HEIGHT * sizeof(char*));
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        grid[i] = (char*)malloc(MAX_WIDTH * sizeof(char));
    }

    // Initialize the grid
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        for (j = 0; j < MAX_WIDTH; j++)
        {
            grid[i][j] = '.';
        }
    }

    // Simulate weather
    srand(time(NULL));
    r = rand() % MAX_HEIGHT;
    c = rand() % MAX_WIDTH;
    grid[r][c] = 'O';

    // Print the grid
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        for (j = 0; j < MAX_WIDTH; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < MAX_HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}