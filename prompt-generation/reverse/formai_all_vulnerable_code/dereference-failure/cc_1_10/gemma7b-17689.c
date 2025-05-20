//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 20

#define EMPTY 0
#define FULL 1

void percolate(int **grid, int w, int h)
{
    srand(time(NULL));
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            if (grid[r][c] == EMPTY)
            {
                int n = rand() % 4;
                if (n == 0)
                {
                    grid[r][c] = FULL;
                }
            }
        }
    }
}

int main()
{
    int **grid = NULL;
    int w, h;

    printf("Enter the width of the grid: ");
    scanf("%d", &w);

    printf("Enter the height of the grid: ");
    scanf("%d", &h);

    grid = (int **)malloc(h * sizeof(int *));
    for (int r = 0; r < h; r++)
    {
        grid[r] = (int *)malloc(w * sizeof(int));
    }

    percolate(grid, w, h);

    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    return 0;
}