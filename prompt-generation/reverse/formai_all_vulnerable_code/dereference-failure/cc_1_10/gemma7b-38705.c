//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, total = 0, current_size = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        current_size++;
        total += arr[i];
    }

    printf("Total cost: %d\n", total);
}

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    printf("Enter the item costs: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}