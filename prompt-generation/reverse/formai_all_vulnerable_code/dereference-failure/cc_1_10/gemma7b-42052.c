//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int i, j, x, y;
    srand(time(NULL));

    grid = malloc(WIDTH * HEIGHT * sizeof(int *));
    for (i = 0; i < WIDTH * HEIGHT; i++)
    {
        grid[i] = malloc(sizeof(int));
        grid[i] = 0;
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
            grid[x][y] = 1;
        }
    }

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("%d ", grid[i][j]);
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < WIDTH * HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}