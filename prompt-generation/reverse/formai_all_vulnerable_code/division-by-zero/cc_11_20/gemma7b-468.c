//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int n, m, i, j, x, y, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX], f[MAX];
    srand(time(NULL));

    n = rand() % MAX;
    m = rand() % MAX;

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % m;
    }

    for (i = 0; i < m; i++)
    {
        b[i] = rand() % n;
    }

    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }

    for (i = 0; i < m; i++)
    {
        d[i] = c[i] % n;
    }

    for (i = 0; i < n; i++)
    {
        e[i] = d[i] * 2;
    }

    for (i = 0; i < m; i++)
    {
        f[i] = e[i] - 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (i = 0; i < m; i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    for (i = 0; i < m; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", e[i]);
    }

    printf("\n");

    for (i = 0; i < m; i++)
    {
        printf("%d ", f[i]);
    }

    printf("\n");

    return 0;
}