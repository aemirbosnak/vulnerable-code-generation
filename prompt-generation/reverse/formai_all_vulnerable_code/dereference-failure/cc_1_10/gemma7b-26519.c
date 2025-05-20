//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 1000

void percolate(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && arr[i][j] < arr[i-1][j] && arr[i-1][j] > 0)
            {
                arr[i][j] = 1;
            }
        }
    }
}

int main()
{
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 2;
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

    free(arr);

    return 0;
}