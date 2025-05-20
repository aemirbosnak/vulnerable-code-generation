//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void greedy_algo(int **arr, int n)
{
    int i, j, k, current_size = 0, maximum_size = 0, current_weight = 0, maximum_weight = 0;

    for (i = 0; i < n; i++)
    {
        current_size += arr[i][0];
        current_weight += arr[i][1];

        if (current_size > maximum_size)
        {
            maximum_size = current_size;
            maximum_weight = current_weight;
        }

        if (current_weight > maximum_weight)
        {
            maximum_size = current_size;
            maximum_weight = current_weight;
        }
    }

    printf("Maximum size of the subset: %d\n", maximum_size);
    printf("Maximum weight of the subset: %d\n", maximum_weight);
}

int main()
{
    int n, i;
    int **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    greedy_algo(arr, n);

    return 0;
}