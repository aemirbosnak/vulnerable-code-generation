//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void spiral_matrix(int **arr, int n)
{
    int i = 0, j = 0, k = 0, d = 1, r = n - 1;

    while (i < r && j < d)
    {
        for (int l = 0; l < n; l++)
        {
            arr[i][j] = k++;
        }

        i++;
        j++;

        if (i == r)
        {
            d++;
        }

        if (j == d)
        {
            r--;
        }
    }
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    spiral_matrix(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    free(arr);

    return 0;
}