//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **grid = NULL;
    int i, j, k, l, r, c, x, y;

    grid = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        grid[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
        }
    }

    grid[10][10] = 1;
    grid[10][11] = 1;
    grid[10][12] = 1;
    grid[11][10] = 1;
    grid[11][11] = 1;
    grid[12][10] = 1;

    for (k = 0; k < 2; k++)
    {
        for (l = 0; l < MAX; l++)
        {
            for (r = 0; r < MAX; r++)
            {
                c = 0;
                x = l - 1;
                y = r - 1;
                if (x >= 0 && grid[x][y] == 1)
                {
                    c++;
                }
                x = l + 1;
                if (x < MAX && grid[x][y] == 1)
                {
                    c++;
                }
                y = r - 1;
                if (y >= 0 && grid[l][y] == 1)
                {
                    c++;
                }
                y = r + 1;
                if (y < MAX && grid[l][y] == 1)
                {
                    c++;
                }

                if (grid[l][r] == 0 && c == 3)
                {
                    grid[l][r] = 1;
                }
                else if (grid[l][r] == 1 && (c == 2 || c == 3))
                {
                    grid[l][r] = 0;
                }
            }
        }
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}