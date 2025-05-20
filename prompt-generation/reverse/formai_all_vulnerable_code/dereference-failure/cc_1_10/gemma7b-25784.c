//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolatesim(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                int x = i;
                int y = j;
                arr[x][y] = 2;
                if (x > 0)
                {
                    arr[x - 1][y] = 2;
                }
                if (x < MAX_SIZE - 1)
                {
                    arr[x + 1][y] = 2;
                }
                if (y > 0)
                {
                    arr[x][y - 1] = 2;
                }
                if (y < MAX_SIZE - 1)
                {
                    arr[x][y + 1] = 2;
                }
            }
        }
    }
}

int main()
{
    int n = MAX_SIZE;
    int **arr = (int **)malloc(n * sizeof(int *) + n * MAX_SIZE * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;

    percolatesim(arr, n);

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