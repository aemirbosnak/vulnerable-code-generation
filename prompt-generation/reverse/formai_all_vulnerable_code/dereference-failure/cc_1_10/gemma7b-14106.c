//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 50

int main()
{
    int i, j, k, n, m, **a, **b;
    time_t t;

    n = DIM;
    m = DIM;
    a = (int *)malloc(n * m * sizeof(int));
    b = (int *)malloc(n * m * sizeof(int));

    t = time(NULL);
    srand(t);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = rand() % 2;
            b[i][j] = a[i][j];
        }
    }

    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (a[i][j] == 1 && b[i][j] == 0)
                {
                    b[i][j] = 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}