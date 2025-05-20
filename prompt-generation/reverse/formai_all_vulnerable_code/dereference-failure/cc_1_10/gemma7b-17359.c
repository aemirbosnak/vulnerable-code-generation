//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void percolate(int **arr, int n, int m)
{
    int i, j, k;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < MAX_SIZE; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    arr[i][j] = 2;
                    if (i > 0)
                        arr[i - 1][j] = 2;
                    if (j > 0)
                        arr[i][j - 1] = 2;
                    if (i < n - 1)
                        arr[i + 1][j] = 2;
                    if (j < m - 1)
                        arr[i][j + 1] = 2;
                }
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