//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 20

#define ALIVE 1
#define DEAD 0

typedef struct Cell {
    int x, y;
    int state;
} Cell;

void initializeGrid(Cell **grid, int size)
{
    grid = malloc(size * sizeof(Cell));
    for (int i = 0; i < size; i++)
    {
        grid[i] = malloc(size * sizeof(Cell));
        for (int j = 0; j < size; j++)
        {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].state = DEAD;
        }
    }
}

void updateCell(Cell **grid, int x, int y)
{
    int aliveNeighbours = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (x + dx >= 0 && x + dx < GRID_SIZE && y + dy >= 0 && y + dy < GRID_SIZE)
            {
                if (grid[x + dx][y + dy].state == ALIVE)
                {
                    aliveNeighbours++;
                }
            }
        }
    }

    if (grid[x][y].state == ALIVE && aliveNeighbours < 2)
    {
        grid[x][y].state = DEAD;
    }
    else if (grid[x][y].state == DEAD && aliveNeighbours == 3)
    {
        grid[x][y].state = ALIVE;
    }
}

void printGrid(Cell **grid)
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }
}

int main()
{
    Cell **grid;
    initializeGrid(&grid, GRID_SIZE);

    // Seed the random number generator
    srand(time(NULL));

    // Create a random initial grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j].state = ALIVE;
        }
    }

    // Simulate life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        printf("Generation %d:\n", gen);
        printGrid(grid);

        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                updateCell(grid, i, j);
            }
        }
    }

    return 0;
}