//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, d, min_dist, centroid[k], cluster[n], ctr = 0, total_dist = 0;

    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        cluster[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            d = abs(arr[i] - centroid[j]);
            min_dist = d;
            if (cluster[i] == -1)
            {
                cluster[i] = j;
                centroid[j] += arr[i];
                total_dist += min_dist;
            }
        }
    }

    printf("Total Distance: %d\n", total_dist);

    for (i = 0; i < n; i++)
    {
        printf("Element: %d, Cluster: %d\n", arr[i], cluster[i]);
    }
}

int main()
{
    int n, k;
    int **arr;

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