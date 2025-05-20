//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, centroids[k], cluster[n];
    double distance, minDistance;

    for (i = 0; i < k; i++)
    {
        centroids[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        cluster[i] = -1;
    }

    for (l = 0; l < k; l++)
    {
        for (i = 0; i < n; i++)
        {
            distance = 0;
            for (j = 0; j < k; j++)
            {
                if (j == l)
                {
                    continue;
                }
                for (d = 0; d < MAX; d++)
                {
                    if (arr[i][d] - centroids[j] == 0)
                    {
                        distance = 0;
                        break;
                    }
                    distance += abs(arr[i][d] - centroids[j]);
                }
                minDistance = distance;
            }
            cluster[i] = l;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to cluster %d\n", arr[i][0], cluster[i]);
    }
}

int main()
{
    int **arr = NULL;
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    cluster(arr, n, k);

    return 0;
}