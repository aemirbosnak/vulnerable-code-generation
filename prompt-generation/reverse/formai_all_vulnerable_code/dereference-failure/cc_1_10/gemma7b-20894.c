//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void initialize(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void printGrid(int **grid, int size)
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

int countAliveNeighbors(int **grid, int i, int j)
{
    int aliveNeighbors = 0;
    int x[] = { -1, 1, 0, 0, -1, 1, 0, 0 };
    int y[] = { 0, 0, -1, 1, 0, 0, -1, 1 };
    int k;

    for (k = 0; k < 8; k++)
    {
        int neighborX = i + x[k];
        int neighborY = j + y[k];

        if (neighborX >= 0 && neighborX < MAX_SIZE && neighborY >= 0 && neighborY < MAX_SIZE && grid[neighborX][neighborY] == 1)
        {
            aliveNeighbors++;
        }
    }

    return aliveNeighbors;
}

void updateGrid(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            int aliveNeighbors = countAliveNeighbors(grid, i, j);

            if (aliveNeighbors < 2)
            {
                grid[i][j] = 0;
            }
            else if (aliveNeighbors == 2)
            {
                grid[i][j] = 1;
            }
        }
    }
}

int main()
{
    int **grid;
    int size = MAX_SIZE;

    initialize(grid, size);

    // Initial grid
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = 1;

    printGrid(grid, size);

    updateGrid(grid, size);

    printGrid(grid, size);

    return 0;
}