//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolatesim(int **arr, int size)
{
    int i, j, k, r, c;
    int **grid = arr;
    int count = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for (r = 0; r < MAX_SIZE; r++)
    {
        for (c = 0; c < MAX_SIZE; c++)
        {
            if (grid[r][c] == 1)
            {
                count++;
                if (r - 1 >= 0 && grid[r - 1][c] == 1)
                    grid[r - 1][c] = 2;
                if (r + 1 < size && grid[r + 1][c] == 1)
                    grid[r + 1][c] = 2;
                if (c - 1 >= 0 && grid[r][c - 1] == 1)
                    grid[r][c - 1] = 2;
                if (c + 1 < size && grid[r][c + 1] == 1)
                    grid[r][c + 1] = 2;
            }
        }
    }

    printf("Number of percolating clusters: %d\n", count);
}

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * size * sizeof(int));
    percolatesim(arr, size);
    free(arr);

    return 0;
}