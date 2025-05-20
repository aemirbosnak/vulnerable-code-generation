//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, minDist, clusterNo, center[k], centroid[k];

    // Calculate the centroid of each cluster
    for (l = 0; l < k; l++)
    {
        centroid[l] = 0;
        for (i = 0; i < n; i++)
        {
            d = abs(arr[i][0] - center[l]) + abs(arr[i][1] - center[l]);
            centroid[l] += d;
        }
        centroid[l] /= n;
    }

    // Assign each data point to a cluster
    for (i = 0; i < n; i++)
    {
        minDist = MAX;
        for (j = 0; j < k; j++)
        {
            d = abs(arr[i][0] - center[j]) + abs(arr[i][1] - center[j]);
            if (d < minDist)
            {
                minDist = d;
                clusterNo = j;
            }
        }
        arr[i][2] = clusterNo;
    }

    // Print the cluster assignment
    printf("Cluster assignment:\n");
    for (i = 0; i < n; i++)
    {
        printf("Data point %d belongs to cluster %d\n", i, arr[i][2]);
    }
}

int main()
{
    int **arr = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Sample data
    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[1][0] = 20;
    arr[1][1] = 30;
    arr[2][0] = 30;
    arr[2][1] = 40;

    int n = 3;
    int k = 2;

    cluster(arr, n, k);

    free(arr);

    return 0;
}