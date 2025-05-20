//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void percolate(int **arr, int n, int r)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == r)
            {
                int x = rand() % n;
                int y = rand() % n;
                if (arr[x][y] == 0)
                {
                    arr[x][y] = r;
                    percolate(arr, n, r);
                }
            }
        }
    }
}

int main()
{
    int **arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    srand(time(NULL));

    int n = MAX_SIZE;
    int r = 5;
    percolate(arr, n, r);

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