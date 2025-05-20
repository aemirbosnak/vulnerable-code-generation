//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void initialize(int **grid, int size)
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

void draw(int **grid, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int rules(int **grid, int size)
{
    int i, j, count = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            int neighbors = 0;
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            if (grid[i][j] == 1 && neighbors < 2) count--;
            if (grid[i][j] == 0 && neighbors == 3) count++;
        }
    }
    return count;
}

int main()
{
    int size = 10;
    int **grid = (int **)malloc(size * sizeof(int *));
    initialize(grid, size);

    grid[2][2] = 1;
    grid[3][2] = 1;
    grid[4][2] = 1;

    draw(grid, size);

    int count = rules(grid, size);
    printf("The number of cells that changed is: %d\n", count);

    free(grid);

    return 0;
}