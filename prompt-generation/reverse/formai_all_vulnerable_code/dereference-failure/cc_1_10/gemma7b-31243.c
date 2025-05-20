//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **a, int n, int k)
{
    int i, j, l, d, min_dist, cluster_size = 0, **c = (int *)malloc(k * sizeof(int));

    for (i = 0; i < k; i++)
    {
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                d = abs(a[i] - a[j]);
                min_dist = fmin(min_dist, d);
            }
        }

        for (l = 0; l < k; l++)
        {
            if (min_dist < c[l])
            {
                c[l]++;
                cluster_size++;
            }
        }
    }

    printf("Number of clusters: %d\n", cluster_size);
    printf("Cluster members:\n");

    for (i = 0; i < k; i++)
    {
        printf("Cluster %d: ", i + 1);
        for (j = 0; j < c[i]; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, k, **a;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter the data points: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    cluster(a, n, k);

    return 0;
}