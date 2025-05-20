//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

int main()
{
    int **grid = NULL;
    int i, j, k;
    int seed = time(NULL);
    srand(seed);

    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < 100; k++)
    {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        if (grid[y][x] == 0)
        {
            grid[y][x] = 1;
        }
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}