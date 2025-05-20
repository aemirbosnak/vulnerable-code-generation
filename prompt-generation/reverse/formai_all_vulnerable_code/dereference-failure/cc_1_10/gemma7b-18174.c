//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void percolate(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (arr[k][l] == 1)
                    {
                        sum++;
                    }
                }
            }
            if (sum > 1)
            {
                arr[i][j] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    percolate(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}