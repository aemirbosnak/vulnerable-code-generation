//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, **c = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        c[i] = -1;
    }
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (d = 0; d < n; d++)
            {
                if (j != d && c[j] == -1 && c[d] == -1)
                {
                    int dist = abs(arr[j] - arr[d]) + abs(arr[j] - arr[d]) + abs(arr[j] - arr[d]);
                    if (dist < 10)
                    {
                        c[j] = d;
                        c[d] = j;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("Cluster: %d\n", c[i]);
    }
    free(c);
}

int main()
{
    int n, k;
    scanf("Enter the number of elements: ", &n);
    scanf("Enter the number of clusters: ", &k);

    int **arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("Enter the element: ", &arr[i]);
    }

    cluster(arr, n, k);

    free(arr);
    return 0;
}