//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, centroid[k], ctr = 0;
    float distance, minDistance, minDist = MAX, dist[k];

    // Calculate centroid
    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
        for (j = 0; j < n; j++)
        {
            distance = sqrtf((arr[j][0] - centroid[i]) * (arr[j][0] - centroid[i]) + (arr[j][1] - centroid[i]) * (arr[j][1] - centroid[i]));
            centroid[i] += distance * arr[j][2];
        }
        centroid[i] /= n;
    }

    // Calculate minimum distance to each centroid
    for (i = 0; i < n; i++)
    {
        minDistance = MAX;
        for (j = 0; j < k; j++)
        {
            dist[j] = sqrtf((arr[i][0] - centroid[j]) * (arr[i][0] - centroid[j]) + (arr[i][1] - centroid[j]) * (arr[i][1] - centroid[j]));
            if (dist[j] < minDistance)
            {
                minDistance = dist[j];
                minDist = minDistance;
            }
        }
        arr[i][2] = minDist;
    }

    // Print the clusters
    for (i = 0; i < n; i++)
    {
        printf("Point %d belongs to cluster %d\n", i, arr[i][2]);
    }
}

int main()
{
    int **arr;
    int n, k;

    // Create an array of points
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(k * sizeof(int));
    }

    // Get the number of points and clusters
    scanf("Enter the number of points: ", &n);
    scanf("Enter the number of clusters: ", &k);

    // Fill the array with points
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coordinates of point %d: ", i);
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // Cluster the points
    cluster(arr, n, k);

    return 0;
}