//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, max_sum = 0, current_sum = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_sum && arr[i][j] > current_size)
            {
                current_sum = arr[i][j];
                current_size = j;
            }
        }
    }

    printf("The maximum sum is: %d", current_sum);
    printf("\nThe maximum size is: %d", current_size);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    scanf("Enter the number of items: ", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the items' weights and values: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}