//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

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
            if (grid[i + x][j + y] == 1)
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
            int neighbor_count = calculate_neighbor_count(grid, i, j);
            if (neighbor_count < 2 || neighbor_count > 3)
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    }
}

int main()
{
    int **grid;
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++)
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));

    initialize_grid(grid, GRID_SIZE);
    print_grid(grid, GRID_SIZE);

    update_grid(grid, GRID_SIZE);
    print_grid(grid, GRID_SIZE);

    free(grid);
    return 0;
}