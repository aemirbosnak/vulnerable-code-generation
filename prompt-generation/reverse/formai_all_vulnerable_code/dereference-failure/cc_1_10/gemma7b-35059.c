//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
// Recursive Percolation Simulator

#include <stdio.h>
#include <stdlib.h>

int percolates(int **arr, int n, int m)
{
    int i, j, k, count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
                arr[i][j] = 2;

                for (k = -1; k <= 1; k++)
                {
                    if (i + k >= 0 && i + k < n && arr[i + k][j] == 1)
                    {
                        arr[i + k][j] = 2;
                    }
                }

                for (k = -1; k <= 1; k++)
                {
                    if (j + k >= 0 && j + k < m && arr[i][j + k] == 1)
                    {
                        arr[i][j + k] = 2;
                    }
                }
            }
        }
    }

    return count;
}

int main()
{
    int n, m, t, i, j, count;
    int **arr;

    scanf("Enter the number of test cases:", &t);

    for (i = 0; i < t; i++)
    {
        scanf("Enter the number of rows and columns:", &n, &m);

        arr = (int **)malloc(n * sizeof(int *));
        for (j = 0; j < n; j++)
        {
            arr[j] = (int *)malloc(m * sizeof(int));
        }

        scanf("Enter the number of occupied cells:", &count);

        for (j = 0; j < count; j++)
        {
            scanf("Enter the row and column of the occupied cell:", &i, &j);
            arr[i][j] = 1;
        }

        printf("The number of percolated cells is: %d\n", percolates(arr, n, m));

        for (j = 0; j < n; j++)
        {
            free(arr[j]);
        }
        free(arr);
    }

    return 0;
}