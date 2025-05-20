//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void percolatesim(int **grid, int size)
{
    int i, j, k, r, s;
    srand(time(NULL));

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < size; k++)
    {
        for (r = 0; r < size; r++)
        {
            s = rand() % 4;
            if (grid[k][r] == 1 && s == 0)
            {
                grid[k][r] = 2;
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size = MAX_SIZE;
    int **grid = NULL;

    grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    percolatesim(grid, size);

    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}