//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

void initialize_grid(int **grid, int size)
{
    int i, j;
    grid = (int *)malloc(size * sizeof(int *));
    for(i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
        for(j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
}

int count_neighbors(int **grid, int i, int j)
{
    int neighbors = 0;
    if(i > 0) neighbors++;
    if(i < MAX_CELLS - 1) neighbors++;
    if(j > 0) neighbors++;
    if(j < MAX_CELLS - 1) neighbors++;
    return neighbors;
}

void update_grid(int **grid, int size)
{
    int i, j, new_grid[MAX_CELLS][MAX_CELLS];
    initialize_grid(new_grid, size);

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            int neighbors = count_neighbors(grid, i, j);
            if(neighbors == 3) new_grid[i][j] = 1;
            else new_grid[i][j] = grid[i][j];
        }
    }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main()
{
    int size = 10;
    int **grid = NULL;
    initialize_grid(grid, size);

    // Simulate game logic
    update_grid(grid, size);

    // Display the grid
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}