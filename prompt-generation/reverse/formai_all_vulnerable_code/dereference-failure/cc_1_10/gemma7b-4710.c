//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algo(int **arr, int n)
{
    int i, j, max_sum = 0, current_sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_sum)
            {
                current_sum = arr[i][j];
            }
        }
    }

    max_sum = current_sum;

    printf("The maximum sum is: %d", max_sum);
}

int main()
{
    int n, i, j;
    int **arr;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the weights and values for each item:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d %d", &arr[i][j], &arr[i][j + MAX]);
        }
    }

    greedy_algo(arr, n);

    return 0;
}