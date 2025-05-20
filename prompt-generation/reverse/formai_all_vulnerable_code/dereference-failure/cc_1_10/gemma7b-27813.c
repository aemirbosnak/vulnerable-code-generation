//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 25

void initialize_grid(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void print_grid(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void calculate_next_generation(int **grid, int size)
{
    int i, j, count, neighbors;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            count = 0;
            neighbors = 0;
            // Check the four neighbors
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            // Calculate the next state of the cell
            if (grid[i][j] == 1 && neighbors < 2) count++;
            if (grid[i][j] == 0 && neighbors == 3) count++;

            grid[i][j] = count;
        }
    }
}

int main()
{
    int **grid;
    int size = GRID_SIZE;
    int iterations = 10;

    grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    initialize_grid(grid, size);

    // Set some initial cells to 1
    grid[5][5] = 1;
    grid[6][5] = 1;
    grid[6][6] = 1;

    print_grid(grid, size);

    for (int iter = 0; iter < iterations; iter++)
    {
        calculate_next_generation(grid, size);
        print_grid(grid, size);
    }

    free(grid);

    return 0;
}