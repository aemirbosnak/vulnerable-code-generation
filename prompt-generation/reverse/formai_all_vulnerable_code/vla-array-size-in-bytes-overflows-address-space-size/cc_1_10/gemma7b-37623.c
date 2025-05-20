//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, min, centroid[k], ctr[k];
    float dist[MAX];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            dist[i] = sqrt(sumSq(arr[i], centroid[j]));
        }
    }

    for (l = 0; l < k; l++)
    {
        min = MAX;
        for (i = 0; i < n; i++)
        {
            if (dist[i] < min)
            {
                min = dist[i];
                ctr[l] = i;
            }
        }

        centroid[l] = arr[ctr[l]];
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to cluster %d\n", arr[i], ctr[i]);
    }
}

int sumSq(int a, int b)
{
    return (a - b) * (a - b) + 1;
}

int main()
{
    int **arr, n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    cluster(arr, n, k);

    return 0;
}