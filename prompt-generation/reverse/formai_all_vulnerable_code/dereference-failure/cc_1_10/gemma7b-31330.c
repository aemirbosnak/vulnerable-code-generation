//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void percolat(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                int r = rand() % 4;
                if (r == 0)
                {
                    arr[i][j] = 1;
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

    percolat(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}