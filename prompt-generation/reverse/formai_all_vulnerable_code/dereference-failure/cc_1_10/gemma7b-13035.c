//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void percolate(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1 && arr[i][j] != arr[i][j-1])
            {
                arr[i][j] = arr[i][j-1] + 1;
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

    // Initialize the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Percolate
    percolate(arr, size);

    // Print the array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}