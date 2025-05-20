//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y, w, h, num_percolation, seed;

    printf("Welcome, dear Watson, to the crime scene. You are facing a case of a stolen diamond.\n");

    // Allocate memory for the grid
    grid = (int**)malloc(MAX_HEIGHT * sizeof(int*));
    for (y = 0; y < MAX_HEIGHT; y++)
    {
        grid[y] = (int*)malloc(MAX_WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (y = 0; y < MAX_HEIGHT; y++)
    {
        for (x = 0; x < MAX_WIDTH; x++)
        {
            grid[y][x] = 0;
        }
    }

    // Set the number of percolation
    num_percolation = rand() % 10 + 1;

    // Percolation
    for (w = 0; w < num_percolation; w++)
    {
        x = rand() % MAX_WIDTH;
        y = rand() % MAX_HEIGHT;
        grid[y][x] = 1;
    }

    // Print the grid
    for (y = 0; y < MAX_HEIGHT; y++)
    {
        for (x = 0; x < MAX_WIDTH; x++)
        {
            printf("%d ", grid[y][x]);
        }
        printf("\n");
    }

    // Free memory
    for (y = 0; y < MAX_HEIGHT; y++)
    {
        free(grid[y]);
    }
    free(grid);

    return 0;
}