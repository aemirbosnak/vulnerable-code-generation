//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm(int **arr, int n)
{
    int i, j, max_sum = 0, current_sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_sum)
            {
                current_sum = arr[i][j];
            }
        }
    }
    max_sum = current_sum;
    printf("Maximum sum: %d\n", max_sum);
}

int main()
{
    int n, i, j;
    scanf("Enter the number of test cases: ", &n);

    for (i = 0; i < n; i++)
    {
        int **arr = (int **)malloc(MAX * sizeof(int *));
        for (j = 0; j < MAX; j++)
        {
            arr[j] = (int *)malloc(MAX * sizeof(int));
        }

        printf("Enter the elements of the matrix: ");
        for (j = 0; j < MAX; j++)
        {
            for (int k = 0; k < MAX; k++)
            {
                scanf("%d ", &arr[j][k]);
            }
        }

        greedy_algorithm(arr, MAX);
        free(arr);
    }

    return 0;
}