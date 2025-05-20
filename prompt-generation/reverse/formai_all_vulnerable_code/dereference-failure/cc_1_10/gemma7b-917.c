//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

void percolat(int **arr, int n, int m)
{
    int i, j, k, flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (k = 0; k < n; k++)
                {
                    for (int l = 0; l < m; l++)
                    {
                        if (arr[k][l] == 1 && k != i && l != j)
                        {
                            if (arr[i][j] == 0)
                            {
                                arr[i][j] = 1;
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    if (flag)
    {
        percolat(arr, n, m);
    }
}

int main()
{
    int n, m, i, j;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    percolat(arr, n, m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}