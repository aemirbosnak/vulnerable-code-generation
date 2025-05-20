//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 256

void percolate(int **grid, int size)
{
    int i, j, k, rand_num;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (grid[i][j] == 1)
            {
                rand_num = rand() % 4;
                if (rand_num == 0)
                {
                    grid[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    int size, num_steps, i, j;
    int **grid;

    printf("Enter the size of the grid: ");
    scanf("%d", &size);

    printf("Enter the number of steps: ");
    scanf("%d", &num_steps);

    grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));

    for (i = 0; i < num_steps; i++)
    {
        percolate(grid, size);
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}