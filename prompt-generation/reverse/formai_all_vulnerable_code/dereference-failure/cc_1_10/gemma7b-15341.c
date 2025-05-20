//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void spiral_search(int **arr, int n, int m)
{
    int i = 0, j = 0, k = 0, l = 0;
    int dir = 1;

    while (i < n && j < m)
    {
        printf("%d ", arr[i][j]);

        switch (dir)
        {
            case 1:
                i++;
                break;
            case 2:
                j++;
                break;
            case 3:
                i--;
                break;
            case 4:
                j--;
                break;
        }

        if (arr[i][j] == -1)
        {
            dir = (dir + 1) % 4;
            l++;
        }

        if (l == n - 1)
        {
            dir = (dir + 1) % 4;
            l = 0;
        }
    }
}

int main()
{
    int n = 5, m = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    arr[2][2] = -1;

    spiral_search(arr, n, m);

    return 0;
}