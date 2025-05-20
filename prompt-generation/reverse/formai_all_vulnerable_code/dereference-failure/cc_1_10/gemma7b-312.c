//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k)
{
    int i, j, l, d, **c = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        c[i] = -1;
    }

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (l = 0; l < n; l++)
            {
                if (j != l)
                {
                    d = abs(arr[j] - arr[l]);
                    if (c[j] == -1 || d < c[j])
                    {
                        c[j] = d;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
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
    {
        scanf("%d", &arr[i]);
    }

    cluster(arr, n, k);

    return 0;
}