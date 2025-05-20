//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void percolat(int **arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1)
            {
                percolat(arr, size);
            }
        }
    }
}

int main()
{
    int **arr;
    int size = MAX_SIZE;

    arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    percolat(arr, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}