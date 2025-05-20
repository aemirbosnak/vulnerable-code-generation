//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void percolate(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] = 2;
                if (i > 0)
                    arr[i - 1][j] = 2;
                if (j > 0)
                    arr[i][j - 1] = 2;
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

    // Randomly fill the array with 1s and 0s
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    percolate(arr, n, m);

    // Print the array
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