//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, **c = (int **)malloc(k * sizeof(int *));
    for (i = 0; i < k; i++)
        c[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            d = 0;
            for (l = 0; l < n; l++)
            {
                if (l != i)
                {
                    d += abs(arr[i] - arr[l]) / MAX;
                }
            }
            c[j][i] = d;
        }
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(c);
}

int main()
{
    int n, k;
    scanf("Enter the number of data points: ", &n);
    scanf("Enter the number of clusters: ", &k);

    int **arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("Enter the data point: ", &arr[i]);
    }

    cluster(arr, n, k);

    free(arr);

    return 0;
}