//Gemma-7B DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n)
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
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    arr[0][0] = 4;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[0][3] = 5;
    arr[0][4] = 1;

    sort(arr, n);

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