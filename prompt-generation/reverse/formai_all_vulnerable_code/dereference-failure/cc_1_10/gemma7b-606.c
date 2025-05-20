//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, total = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_size; j++)
        {
            if (arr[i][j] > arr[i][current_size])
            {
                current_size++;
            }
        }

        total += arr[i][current_size];
    }

    printf("Total cost: %d", total);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the item costs: ");
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