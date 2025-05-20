//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

int percolate(int **arr, int n, int r)
{
    int i, j, k, count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == r)
            {
                count++;
                arr[i][j] = 0;
                percolate(arr, n, r);
            }
        }
    }

    return count;
}

int main()
{
    int n, r, count;
    int **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the number of rounds: ");
    scanf("%d", &r);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    count = percolate(arr, n, r);

    printf("The number of percolated cells is: %d", count);

    return 0;
}