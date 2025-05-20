//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void rearrange(int **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][0] > arr[j][0])
            {
                int temp = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("Enter the number of elements: ", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            scanf("Enter the element: ", &arr[i][j]);
        }
    }

    rearrange(arr, n);

    printf("The rearranged array is:\n");
    for (int i = 0; i < n; i++)
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