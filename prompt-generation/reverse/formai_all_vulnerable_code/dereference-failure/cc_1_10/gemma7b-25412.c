//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

void percolate(int **arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 0)
            {
                int r = rand() % size;
                int c = rand() % size;
                if (arr[r][c] == 1)
                {
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int **arr = NULL;
    int size = MAX_SIZE;

    arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int *)malloc(size * sizeof(int));
    }

    percolate(arr, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}