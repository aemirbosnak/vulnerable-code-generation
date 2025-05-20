//Gemma-7B DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv_sort(int **arr, int n)
{
    int i, j, k, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (*(*(arr + min_idx)) > *(*(arr + j)))
            {
                min_idx = j;
            }
        }
        int temp = *(arr + min_idx);
        *(arr + min_idx) = *(arr + i);
        *(arr + i) = temp;
    }
}

int main()
{
    int n = 10;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Populate the array
    arr[0][0] = 5;
    arr[0][1] = 3;
    arr[0][2] = 8;
    arr[0][3] = 2;
    arr[0][4] = 4;
    arr[0][5] = 7;
    arr[0][6] = 1;
    arr[0][7] = 6;
    arr[0][8] = 9;
    arr[0][9] = 3;

    inv_sort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}