//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void find_best_match(int **arr, int n);

int main()
{
    int n = 5;
    int **arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }

    find_best_match(arr, n);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}

void find_best_match(int **arr, int n)
{
    int best_match = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            int current_match = arr[i][j];
            if (current_match > best_match)
            {
                best_match = current_match;
            }
        }
    }

    printf("The best match is: %d\n", best_match);
}