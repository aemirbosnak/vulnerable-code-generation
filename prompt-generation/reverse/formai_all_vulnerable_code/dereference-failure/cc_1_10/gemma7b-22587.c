//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void percolate(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                int k = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (arr[i + r][j + c] != 0)
                        {
                            arr[i][j] = 1;
                            k++;
                        }
                    }
                }
                if (k > 0)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int **arr = (int **)malloc(DIM * sizeof(int *));
    for (int i = 0; i < DIM; i++)
    {
        arr[i] = (int *)malloc(DIM * sizeof(int));
    }

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            arr[i][j] = 0;
        }
    }

    percolate(arr, DIM, DIM);

    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}