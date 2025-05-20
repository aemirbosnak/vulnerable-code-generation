//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int **arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 4;
    arr[0][1] = 2;
    arr[0][2] = 8;
    arr[0][3] = 3;
    arr[0][4] = 6;

    insertionSort(arr, n);

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