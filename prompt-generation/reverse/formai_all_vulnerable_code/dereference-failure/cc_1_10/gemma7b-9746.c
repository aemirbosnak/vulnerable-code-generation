//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, total_size = 0, current_size = MAX_SIZE;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < current_size; j++)
        {
            if (arr[i][j] == 1)
            {
                total_size++;
                arr[i][j] = 0;
                current_size--;
                break;
            }
        }
    }

    printf("Total size of the packed items: %d", total_size);
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

    printf("Enter the item sizes: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}