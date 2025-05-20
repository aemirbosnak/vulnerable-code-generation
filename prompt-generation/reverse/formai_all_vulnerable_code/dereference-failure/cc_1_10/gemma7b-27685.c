//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **arr, int n)
{
    int i, j, count = 0, prev = 0, flag = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < prev; j++)
        {
            if (*arr[i] == *arr[j])
            {
                flag = 1;
                count++;
            }
        }
        if (flag)
        {
            *arr[i] = count;
            prev = count;
            count = 0;
        }
        prev++;
    }
}

int main()
{
    int n, i, *arr, **arr_ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr_ptr = (int **)malloc(n * sizeof(int *));
    arr = *arr_ptr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    compress(arr_ptr, n);

    printf("Compressed elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    free(arr_ptr);

    return 0;
}