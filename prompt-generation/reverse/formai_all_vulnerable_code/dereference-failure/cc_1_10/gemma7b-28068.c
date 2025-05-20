//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main()
{
    int n, i, j, k, d, **a, **c, **b;

    printf("Enter the number of clusters: ");
    scanf("%d", &n);

    a = (int *)malloc(n * MAX);
    c = (int *)malloc(n * MAX);
    b = (int *)malloc(n * MAX);

    printf("Enter the number of data points: ");
    scanf("%d", &d);

    a = (int *)realloc(a, d * MAX);

    printf("Enter the data points: ");
    for (i = 0; i < d; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        c[i] = -1;
    }

    for (i = 0; i < d; i++)
    {
        int min = MAX;
        for (j = 0; j < n; j++)
        {
            int dist = abs(a[i] - a[j]);
            if (dist < min)
            {
                min = dist;
                c[i] = j;
            }
        }
    }

    printf("The cluster memberships are: ");
    for (i = 0; i < d; i++)
    {
        printf("%d ", c[i]);
    }

    free(a);
    free(c);
    free(b);

    return 0;
}