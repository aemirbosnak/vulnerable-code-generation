//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void greedy_algo(int **arr, int n)
{
    int i, j, total_cost = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (arr[i][j] != 0)
            {
                if (current_size < MAX_SIZE)
                {
                    current_size++;
                    total_cost += arr[i][j];
                }
            }
        }
    }

    printf("Total cost: %d\n", total_cost);
    printf("Current size: %d\n", current_size);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    scanf("Enter the number of items: ", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Populate the array with item sizes and costs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            scanf("Enter the size of item %d: ", &arr[i][j]);
            scanf("Enter the cost of item %d: ", &arr[i][j]);
        }
    }

    greedy_algo(arr, n);

    free(arr);

    return 0;
}