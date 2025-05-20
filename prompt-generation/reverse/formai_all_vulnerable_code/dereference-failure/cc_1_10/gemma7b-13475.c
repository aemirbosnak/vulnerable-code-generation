//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, c = 0, **p = (int **)malloc(k * sizeof(int *));

    for (i = 0; i < k; i++)
    {
        p[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            d = 0;
            for (c = 0; c < n; c++)
            {
                if (c != i)
                {
                    d += abs(arr[i] - arr[c]) * abs(arr[i] - arr[c]);
                }
            }
            p[j][i] = d;
        }
    }

    for (i = 0; i < n; i++)
    {
        int min = MAX;
        for (j = 0; j < k; j++)
        {
            if (p[j][i] < min)
            {
                min = p[j][i];
            }
        }
        arr[i] = j + 1;
    }

    free(p);
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

    printf("The cluster labels are:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }

    free(arr);

    return 0;
}