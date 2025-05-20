//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algo(int **arr, int n)
{
    int i, j, k, max_sum = 0, current_sum = 0;
    for (i = 0; i < n; i++)
    {
        current_sum = 0;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                for (k = 0; k < MAX; k++)
                {
                    if (arr[i][k] + arr[j][k] > current_sum)
                    {
                        current_sum = arr[i][k] + arr[j][k];
                    }
                }
            }
        }
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }
    }
    printf("The maximum sum is: %d\n", max_sum);
}

int main()
{
    int n, i, j;
    int **arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algo(arr, n);

    return 0;
}