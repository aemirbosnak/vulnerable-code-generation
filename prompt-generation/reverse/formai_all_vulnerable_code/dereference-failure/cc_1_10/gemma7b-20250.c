//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdlib.h>
#include <stdio.h>

#define DIM 20

int main()
{
    int **arr = NULL;
    int i, j, k, n, m;

    n = DIM;
    m = DIM;
    arr = (int**)malloc(n * sizeof(int*) + m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    k = 0;
    while (k < 100)
    {
        i = rand() % n;
        j = rand() % m;
        if (arr[i][j] == 0)
        {
            arr[i][j] = 1;
            k++;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}