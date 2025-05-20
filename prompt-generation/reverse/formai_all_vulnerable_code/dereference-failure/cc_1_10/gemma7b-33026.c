//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void percolate(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size && arr[i] > arr[j]; j++)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **arr = (int **)malloc(size * sizeof(int *));
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

    // Percolate the array
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

    free(arr);

    return 0;
}