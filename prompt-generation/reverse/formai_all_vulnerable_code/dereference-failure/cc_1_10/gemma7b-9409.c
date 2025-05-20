//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, **c, ctr = 0;
    c = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            l = 0;
            for (d = 0; d < n; d++)
            {
                if (i != d)
                {
                    if (arr[i] - arr[d] <= 5)
                        l++;
                }
            }
            c[j] += l;
        }
    }

    for (i = 0; i < k; i++)
    {
        printf("Cluster %d has %d members\n", i + 1, c[i]);
    }

    free(c);
}

int main()
{
    int n, k, **arr;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the number of clusters:");
    scanf("%d", &k);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    cluster(arr, n, k);

    return 0;
}