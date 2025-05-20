//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void spiralOrder(int **arr, int n, int m)
{
    int i = 0, j = 0, k = 0, direction = 0;
    while (i < n && j < m)
    {
        // Print the elements of the current block
        for (int r = i; r < i + 2 && r < n; r++)
        {
            for (int c = j; c < j + 2 && c < m; c++)
            {
                printf("%d ", arr[r][c]);
            }
        }

        // Change direction if necessary
        if (direction == 0)
        {
            i++;
            direction = 1;
        }
        else if (direction == 1)
        {
            j++;
            direction = 2;
        }
        else if (direction == 2)
        {
            i--;
            direction = 0;
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

    // Populate the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = i + j;
        }
    }

    spiralOrder(arr, n, m);

    free(arr);

    return 0;
}