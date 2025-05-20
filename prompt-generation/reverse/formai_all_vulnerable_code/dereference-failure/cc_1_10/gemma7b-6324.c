//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm(int **arr, int n)
{
    int i, j, current_size = 0, total_size = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] != 0)
            {
                if (current_size < j)
                {
                    current_size = j;
                }
            }
        }
        total_size += current_size;
        current_size = 0;
    }
    printf("Total size of the matrix: %d\n", total_size);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    free(arr);

    return 0;
}