//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int n = MAX;
    int i, j, k, l, m;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    k = 0;
    l = 0;
    m = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = k;
            k++;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}