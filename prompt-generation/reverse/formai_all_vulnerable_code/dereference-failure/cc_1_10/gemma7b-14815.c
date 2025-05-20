//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void percolate(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                int r = rand() % n;
                int c = rand() % n;
                if (arr[r][c] == 1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int n = MAX;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    percolate(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}