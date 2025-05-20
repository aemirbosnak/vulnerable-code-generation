//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void spiral_array(int **arr, int n, int m)
{
    int i = 0, j = 0, k = 0, l = 0, d = 1;
    arr = (int **)malloc(n * m * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = l++;
        }
    }

    k = 0;
    while (k < n * m)
    {
        switch (d)
        {
            case 1:
                i = k / m;
                j = k % m;
                printf("%d ", arr[i][j]);
                k++;
                break;
            case 2:
                i = k / m;
                j = k % m;
                printf("%d ", arr[i][j]);
                k++;
                d = 3;
                break;
            case 3:
                i = k / m;
                j = k % m;
                printf("%d ", arr[i][j]);
                k++;
                d = 2;
                break;
            case 4:
                i = k / m;
                j = k % m;
                printf("%d ", arr[i][j]);
                k++;
                d = 1;
                break;
        }
    }
}

int main()
{
    int n = 5, m = 5;
    int **arr;

    spiral_array(&arr, n, m);

    return 0;
}