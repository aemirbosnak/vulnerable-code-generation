//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define FULL 1
#define BLOCKED 2

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array of cells
    int **cells = (int**)malloc(WIDTH * sizeof(int*));
    for (int i = 0; i < WIDTH; i++)
    {
        cells[i] = (int*)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the cells
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            cells[i][j] = EMPTY;
        }
    }

    // Percolation simulation
    int num_steps = 0;
    while (!is_percolation_complete(cells))
    {
        // Randomly choose a cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is empty and not blocked, fill it
        if (cells[x][y] == EMPTY && cells[x][y] != BLOCKED)
        {
            cells[x][y] = FULL;
        }

        num_steps++;
    }

    // Print the final state of the cells
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the cells
    for (int i = 0; i < WIDTH; i++)
    {
        free(cells[i]);
    }
    free(cells);

    printf("Number of steps: %d\n", num_steps);

    return 0;
}

int is_percolation_complete(int **cells)
{
    // Check if all cells in the bottom row are full
    for (int i = 0; i < WIDTH; i++)
    {
        if (cells[WIDTH - 1][i] != FULL)
        {
            return 0;
        }
    }

    return 1;
}