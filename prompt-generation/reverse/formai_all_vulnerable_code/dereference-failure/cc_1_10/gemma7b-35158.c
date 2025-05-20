//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

void greedy_algorithm(int **arr, int n, int m)
{
    int i, j, k, sum = 0, max_sum = INT_MIN, current_sum = INT_MAX;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            current_sum = sum + arr[i][j];
            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }

    printf("The maximum sum is: %d\n", max_sum);
}

int main()
{
    int n, m, i, j;
    int **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n, m);

    return 0;
}