//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void searching(int **arr, int n, int target)
{
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == target)
        {
            printf("Target found at index %d\n", mid);
            return;
        }
        else if (arr[mid] < target)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    printf("Target not found\n");
}

int main()
{
    int n = 5;
    int target = 5;

    int **arr = (int **)malloc(n * sizeof(int *));
    arr[0] = (int *)malloc(n * sizeof(int));
    arr[1] = (int *)malloc(n * sizeof(int));
    arr[2] = (int *)malloc(n * sizeof(int));
    arr[3] = (int *)malloc(n * sizeof(int));
    arr[4] = (int *)malloc(n * sizeof(int));

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    searching(arr, n, target);

    return 0;
}