//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    int **arr = NULL;
    int i, j, k, n;

    n = N;
    arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    k = 0;
    while(k < n * n)
    {
        int r = rand() % n;
        int c = rand() % n;
        if(arr[r][c] == 0)
        {
            arr[r][c] = 1;
            k++;
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}