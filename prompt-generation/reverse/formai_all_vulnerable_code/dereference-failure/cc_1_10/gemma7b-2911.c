//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int percolate(int ***arr, int n, int m, int r)
{
    int i, j, k, count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < r; k++)
            {
                if (arr[i][j][k] == 1)
                {
                    count++;
                }
            }
        }
    }

    if (count == n * m * r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, m, r;
    int ***arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    printf("Enter the number of iterations: ");
    scanf("%d", &r);

    arr = (int ***)malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int **)malloc(m * sizeof(int *));
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = (int *)malloc(r * sizeof(int));
        }
    }

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < r; k++)
            {
                arr[i][j][k] = 0;
            }
        }
    }

    // Percolate the array
    int result = percolate(arr, n, m, r);

    // Print the result
    if (result == 1)
    {
        printf("The array is percolated.\n");
    }
    else
    {
        printf("The array is not percolated.\n");
    }

    return 0;
}