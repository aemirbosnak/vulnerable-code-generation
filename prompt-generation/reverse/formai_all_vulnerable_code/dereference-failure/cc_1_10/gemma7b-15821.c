//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, min_dist, cluster_size = 0, *clust = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
    {
        clust[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            d = abs(arr[i] - arr[j]);
            min_dist = d;
            if (clust[i] == -1 && clust[j] == -1 && min_dist < cluster_size)
            {
                clust[i] = clust[j] = ++cluster_size;
            }
        }
    }

    printf("Clusters:\n");
    for (i = 0; i < cluster_size; i++)
    {
        printf("Cluster %d: ", i + 1);
        for (j = 0; j < n; j++)
        {
            if (clust[j] == i + 1)
            {
                printf("%d ", arr[j]);
            }
        }
        printf("\n");
    }

    free(clust);
}

int main()
{
    int n, k;
    scanf("Enter the number of elements: ", &n);
    scanf("Enter the number of clusters: ", &k);

    int **arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }

    cluster(arr, n, k);

    free(arr);
    return 0;
}