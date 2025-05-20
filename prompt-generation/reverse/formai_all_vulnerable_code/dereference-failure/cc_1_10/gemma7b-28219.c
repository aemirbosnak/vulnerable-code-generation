//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void percolate(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > 0)
            {
                int x = i + 1;
                int y = j + 1;
                if (x < MAX && y < MAX && arr[x][y] == 0)
                {
                    arr[x][y] = arr[i][j] / 2;
                }
            }
        }
    }
}

int main()
{
    int **arr = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = rand() % 5;
        }
    }

    percolate(arr, MAX);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}