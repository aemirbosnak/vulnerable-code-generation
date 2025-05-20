//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void percolate(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size && arr[j] > arr[i]; j++)
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

    // Initialize array with random numbers
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 11;
        }
    }

    percolate(arr, size);

    // Print the sorted array
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