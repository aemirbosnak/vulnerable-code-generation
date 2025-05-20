//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void percolate(int **arr, int n, int m)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int x = i + rand() % 2;
                int y = j + rand() % 2;
                if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 0)
                {
                    arr[x][y] = 1;
                }
            }
        }
    }
}

int main()
{
    int n = 10;
    int m = 10;
    int **arr = (int **)malloc(n * sizeof(int *) + m * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    percolate(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}