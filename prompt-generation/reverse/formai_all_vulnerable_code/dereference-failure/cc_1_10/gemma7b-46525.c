//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void greedy_algo(int **arr, int n)
{
    int i, j, k, max_sum = 0, current_sum = 0;
    for (i = 0; i < n; i++)
    {
        current_sum = 0;
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (k = 0; k < n; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }
                current_sum = current_sum + arr[k];
            }
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }
    printf("The maximum sum is: %d", max_sum);
}

int main()
{
    int n, i;
    scanf("Enter the number of elements: ", &n);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }
    greedy_algo(arr, n);
    return 0;
}