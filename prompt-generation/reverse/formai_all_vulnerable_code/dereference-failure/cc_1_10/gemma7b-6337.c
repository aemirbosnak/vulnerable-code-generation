//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void percolate(int **arr, int n, int i)
{
    if (i >= n)
    {
        return;
    }

    if (arr[i] == 0)
    {
        arr[i] = 1;
        percolate(arr, n, i + 1);
    }
}

int main()
{
    int n = MAX;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    percolate(arr, n, 0);

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