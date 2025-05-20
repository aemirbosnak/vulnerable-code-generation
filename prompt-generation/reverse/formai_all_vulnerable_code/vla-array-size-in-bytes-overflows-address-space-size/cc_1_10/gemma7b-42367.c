//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, min, centroid[k], center[k];

    for (i = 0; i < k; i++)
    {
        centroid[i] = 0;
        center[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        min = MAX;
        for (j = 0; j < k; j++)
        {
            l = 0;
            for (d = 0; d < n; d++)
            {
                if (arr[d] != arr[i])
                {
                    center[j] += abs(arr[d] - arr[i]);
                    l++;
                }
            }
            center[j] /= l;
            if (min > center[j])
            {
                min = center[j];
                centroid[i] = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Element %d belongs to Cluster %d\n", arr[i], centroid[i]);
    }
}

int main()
{
    int **arr;
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    cluster(arr, n, k);

    return 0;
}