//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void percolate(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                int x = rand() % MAX;
                if (x < arr[i][j])
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    int **arr;
    arr = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = rand() % 2;
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

    return 0;
}