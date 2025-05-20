//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 10

void percolate(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && arr[i][j-1] == 1)
            {
                arr[i][j] = 1;
            }
        }
    }
}

int main()
{
    int **arr;
    arr = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    percolate(arr, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}