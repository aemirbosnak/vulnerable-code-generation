//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void percolate(int **arr, int n, int m)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % MAX;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= 5)
            {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 5;
    int m = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    percolate(arr, n, m);

    return 0;
}