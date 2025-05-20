//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void spiral_matrix(int **arr, int n)
{
    int i = 0, j = 0, k = 0, direction = 0, x = n, y = n;
    arr = (int **)malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (k = 0; k < n * n; k++)
    {
        arr[i][j] = k + 1;
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

        if (i == x || j == y)
        {
            direction++;
            if (direction == 4)
            {
                direction = 0;
            }
            x--;
            y--;
        }
    }
}

int main()
{
    int n = 5;
    int **arr = NULL;
    spiral_matrix(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}