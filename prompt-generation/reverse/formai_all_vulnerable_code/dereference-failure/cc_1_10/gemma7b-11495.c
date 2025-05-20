//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    int n, i, j, k, l, m, x, y, z;
    int **arr = NULL;

    scanf("Enter the number of tests:", &n);

    for (k = 0; k < n; k++)
    {
        arr = (int **)malloc(MAX_SIZE * sizeof(int *));
        for (l = 0; l < MAX_SIZE; l++)
        {
            arr[l] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        scanf("Enter the number of rows and columns:", &m);
        scanf("Enter the number of elements:", &x);

        for (i = 0; i < x; i++)
        {
            scanf("Enter the element:", &y);
            arr[i][0] = y;
        }

        for (j = 0; j < m; j++)
        {
            for (i = 0; i < x; i++)
            {
                arr[i][j] = arr[i][0] + j;
            }
        }

        for (i = 0; i < x; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        free(arr);
    }

    return 0;
}