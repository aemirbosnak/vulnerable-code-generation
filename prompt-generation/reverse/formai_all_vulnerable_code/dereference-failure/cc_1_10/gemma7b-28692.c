//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, max_sum = 0, current_sum = 0, current_size = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (arr[i][j] != 0)
            {
                current_sum += arr[i][j];
                current_size++;
                if (current_sum > max_sum)
                {
                    max_sum = current_sum;
                    current_size = current_size;
                }
            }
        }
    }

    printf("Maximum sum: %d\n", max_sum);
    printf("Maximum size: %d\n", current_size);
}

int main()
{
    int n;
    scanf("Enter the number of items: ", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            scanf("Enter the weight and value of item %d: ", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}