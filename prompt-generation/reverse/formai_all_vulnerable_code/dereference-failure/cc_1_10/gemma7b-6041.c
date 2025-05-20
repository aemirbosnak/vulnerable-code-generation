//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, **c = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            d = 0;
            for (l = 0; l < n; l++)
            {
                if (l != i)
                {
                    if (arr[i] - arr[l] < d)
                        d = arr[i] - arr[l];
                }
            }
            c[j] += d;
        }
    }

    for (i = 0; i < k; i++)
    {
        printf("Cluster %d: ", i + 1);
        for (j = 0; j < n; j++)
        {
            if (c[i] == c[j])
                printf("%d ", arr[j]);
        }
        printf("\n");
    }

    free(c);
}

int main()
{
    int n, k, **arr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    cluster(arr, n, k);

    return 0;
}