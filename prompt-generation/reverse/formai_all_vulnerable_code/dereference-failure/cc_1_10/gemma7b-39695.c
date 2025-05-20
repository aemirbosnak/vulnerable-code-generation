//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

void greedy_algorithm(int **arr, int n)
{
    int i, j, total_weight = 0, current_weight = 0, selected_items = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (arr[i][j] > current_weight)
            {
                current_weight = arr[i][j];
                selected_items++;
            }
        }
    }

    total_weight = selected_items * current_weight;

    printf("Total weight: %d\n", total_weight);
    printf("Number of selected items: %d\n", selected_items);
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
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    printf("Enter the item weights and values: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}