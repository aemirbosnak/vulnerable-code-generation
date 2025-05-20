//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm(int **arr, int n)
{
    int i, j, total = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] != 0)
            {
                if (current_size < arr[i][j])
                {
                    current_size = arr[i][j];
                    total += current_size;
                }
            }
        }
    }

    printf("Total weight: %d", total);
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

    printf("Enter the weights and values for each item: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}