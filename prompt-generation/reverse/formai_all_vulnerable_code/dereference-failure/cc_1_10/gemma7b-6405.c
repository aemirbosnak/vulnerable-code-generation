//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void search(int **arr, int n, int key)
{
    int i = 0;
    int j = n - 1;
    int mid = 0;

    while (i <= j)
    {
        mid = (i + j) / 2;
        if (arr[mid] == key)
        {
            printf("Key found at index %d\n", mid);
            return;
        }
        else if (arr[mid] < key)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    printf("Key not found\n");
}

int main()
{
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 10;
    arr[0][1] = 20;
    arr[0][2] = 30;
    arr[0][3] = 40;
    arr[0][4] = 50;

    search(arr, n, 30);

    return 0;
}