//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 10

int main()
{
    char **grid = NULL;
    int width, height;

    // Generate random grid size
    width = rand() % MAX_WIDTH + 1;
    height = rand() % MAX_HEIGHT + 1;

    // Allocate memory for the grid
    grid = malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        grid[i] = malloc(width * sizeof(char) + 1);
    }

    // Fill the grid with ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            grid[h][w] = rand() % 32 + 32;
        }
    }

    // Print the ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            printf("%c ", grid[h][w]);
        }
        printf("\n");
    }

    // Free the memory
    for (int h = 0; h < height; h++)
    {
        free(grid[h]);
    }
    free(grid);

    return 0;
}