//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **arr = NULL;
    int i, j, k, l, r, c, n, m;

    n = m = MAX;
    arr = (int **)malloc(n * sizeof(int *) + m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    r = 0;
    l = 0;
    c = 0;

    while (r < n && l < m)
    {
        if (arr[r][l] == 0)
        {
            arr[r][l] = 1;
            c++;
            if (c == 5)
            {
                printf("BOOM!!!\n");
                exit(0);
            }
            r++;
            l++;
        }
        else
        {
            l++;
        }
    }

    printf("No Boom!!!\n");

    return 0;
}