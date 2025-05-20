//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void ShapeShifting(int n)
{
    int i, j, k, l, m, x, y, z;
    int **a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            x = rand() % n;
            y = rand() % n;
            a[x][y] = 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                printf("(%d, %d) ", i, j);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
}

int main()
{
    ShapeShifting(10);
    return 0;
}