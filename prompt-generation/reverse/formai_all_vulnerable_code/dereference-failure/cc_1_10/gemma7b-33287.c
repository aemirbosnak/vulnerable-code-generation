//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, min_dist, centroid_idx, cluster_idx[n];
    float centroid[k];

    // Calculate centroids
    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
        for (j = 0; j < n; j++)
        {
            d = abs(arr[j][0] - centroid[i]) + abs(arr[j][1] - centroid[i]);
            centroid[i] += d;
        }
        centroid[i] /= n;
    }

    // Assign each point to a cluster
    for (i = 0; i < n; i++)
    {
        min_dist = MAX;
        for (j = 0; j < k; j++)
        {
            d = abs(arr[i][0] - centroid[j]) + abs(arr[i][1] - centroid[j]);
            if (d < min_dist)
            {
                min_dist = d;
                centroid_idx = j;
            }
        }
        cluster_idx[i] = centroid_idx;
    }

    // Print cluster indices
    for (i = 0; i < n; i++)
    {
        printf("Point %d belongs to Cluster %d\n", i, cluster_idx[i]);
    }
}

int main()
{
    int n, k;
    int **arr;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    // Get the points
    printf("Enter the coordinates of each point (x, y):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    cluster(arr, n, k);

    return 0;
}