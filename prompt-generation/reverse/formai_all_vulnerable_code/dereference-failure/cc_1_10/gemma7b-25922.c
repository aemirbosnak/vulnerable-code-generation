//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void cluster(int **arr, int n)
{
    int i, j, k, d, centroid[MAX], cluster_size[MAX] = {0};
    double distance, min_distance, total_distance = 0.0;

    for (i = 0; i < n; i++)
    {
        centroid[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            distance = 0.0;
            for (k = 0; k < MAX; k++)
            {
                if (arr[i][k] - arr[j][k] != 0)
                {
                    distance += (arr[i][k] - arr[j][k]) * (arr[i][k] - arr[j][k]);
                }
            }

            min_distance = distance;
            if (centroid[i] == -1 || min_distance < total_distance)
            {
                total_distance = min_distance;
                centroid[i] = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Cluster member: %d, Centroid: %d\n", arr[i][0], centroid[i]);
    }
}

int main()
{
    int **arr = NULL;
    int n = 0;

    scanf("Enter the number of data points: ", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the data points: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    cluster(arr, n);

    return 0;
}