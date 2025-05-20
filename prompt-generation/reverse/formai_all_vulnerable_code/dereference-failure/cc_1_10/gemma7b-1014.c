//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void percolatesim(int n, int **arr)
{
    int i, j, k, r, c;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = rand() % MAX;
        }
    }

    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (arr[r][c] > 0)
            {
                k = rand() % MAX;
                if (k < arr[r][c])
                {
                    arr[r][c] = 0;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    percolatesim(n, arr);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}