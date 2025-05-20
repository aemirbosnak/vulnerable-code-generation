//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define CELL_SIZE 20

#define ALIVE 1
#define DEAD 0

void initialize_grid(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = DEAD;
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

int calculate_neighbor_count(int **grid, int i, int j)
{
    int count = 0;
    int x, y;

    for (x = -1; x <= 1; x++)
    {
        for (y = -1; y <= 1; y++)
        {
            if (x == 0 && y == 0)
                continue;

            if (grid[i + x][j + y] == ALIVE)
                count++;
        }
    }

    return count;
}

void update_grid(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            int neighbors = calculate_neighbor_count(grid, i, j);

            if (neighbors < 2)
                grid[i][j] = DEAD;
            else if (neighbors == 2)
                grid[i][j] = ALIVE;
            else if (neighbors > 2)
                grid[i][j] = DEAD;
        }
    }
}

int main()
{
    int **grid;
    int size = GRID_SIZE;

    grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    initialize_grid(grid, size);

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of alive and dead cells
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (rand() % 2 == 0)
                grid[i][j] = ALIVE;
        }
    }

    print_grid(grid, size);

    update_grid(grid, size);

    print_grid(grid, size);

    return 0;
}