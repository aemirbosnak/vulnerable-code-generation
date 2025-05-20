//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolat(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && arr[i - 1][j] == 1)
            {
                arr[i][j] = 2;
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

    // Initialize the array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Create a random pattern
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    // Percolation
    percolat(arr, MAX_SIZE);

    // Print the result
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