//Gemma-7B DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void sortByAge(int **arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((*arr[i]) > (*arr[j]))
            {
                int temp = *arr[i];
                *arr[i] = *arr[j];
                *arr[j] = temp;
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

    // Fill the array with sample data
    arr[0][0] = 25;
    arr[0][1] = 30;
    arr[0][2] = 40;
    arr[0][3] = 20;
    arr[0][4] = 35;

    // Sort the array by age
    sortByAge(arr, MAX_SIZE);

    // Print the sorted array
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}