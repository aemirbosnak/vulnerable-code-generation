//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void spiral_fill(int **arr, int n, int m)
{
    int i = 0, j = 0, k = 0, direction = 0;

    while (i < n && j < m)
    {
        arr[i][j] = k++;

        switch (direction)
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

        if (arr[i][j] == arr[n - 1][m - 1])
        {
            direction = (direction + 1) % 4;
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

    spiral_fill(arr, n, m);

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