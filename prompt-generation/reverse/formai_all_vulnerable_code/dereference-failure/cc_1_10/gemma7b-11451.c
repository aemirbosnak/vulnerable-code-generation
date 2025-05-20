//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdlib.h>
#include <time.h>

#define DIM 50

int main()
{
    int **grid = NULL;
    int **rand_nums = NULL;

    grid = (int **)malloc(DIM * sizeof(int *));
    rand_nums = (int **)malloc(DIM * sizeof(int *));

    for(int i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
        rand_nums[i] = (int *)malloc(DIM * sizeof(int));
    }

    srand(time(NULL));

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            rand_nums[i][j] = rand() % 2;
            grid[i][j] = 0;
        }
    }

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            if(rand_nums[i][j] == 1)
            {
                grid[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}