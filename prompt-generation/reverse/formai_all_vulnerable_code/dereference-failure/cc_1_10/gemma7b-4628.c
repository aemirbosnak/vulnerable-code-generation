//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void percolate(int **arr, int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == r)
            {
                arr[i][j] = 0;
                if (i > 0) percolate(arr, n, r);
                if (j > 0) percolate(arr, n, r);
            }
        }
    }
}

int main()
{
    int n;
    scanf("Enter the number of rows:", &n);
    int m;
    scanf("Enter the number of columns:", &m);
    int r;
    scanf("Enter the number of rounds:", &r);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    percolate(arr, n, r);

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