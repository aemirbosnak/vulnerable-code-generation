//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void spiral_search(int **arr, int n, int m)
{
    int i = 0, j = 0, k = 0, d = 1;
    while (i < n && j < m)
    {
        printf("%d ", arr[i][j]);
        switch (k)
        {
            case 0:
                i++;
                break;
            case 1:
                j++;
                break;
            case 2:
                i--;
                break;
            case 3:
                j--;
                break;
        }
        k = (k + 1) % 4;
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

    arr[0][0] = 1;
    arr[1][0] = 2;
    arr[2][0] = 3;
    arr[3][0] = 4;
    arr[4][0] = 5;
    arr[0][1] = 6;
    arr[0][2] = 7;
    arr[1][2] = 8;
    arr[2][2] = 9;
    arr[2][3] = 10;
    arr[3][3] = 11;
    arr[4][3] = 12;
    arr[3][4] = 13;
    arr[4][4] = 14;

    spiral_search(arr, n, m);

    return 0;
}