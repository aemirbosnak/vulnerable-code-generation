//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void search(int **arr, int n, int target)
{
    int i, j, found = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("Target found.\n");
    }
    else
    {
        printf("Target not found.\n");
    }
}

int main()
{
    int n, target;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &n);
    scanf("Enter the target: ", &target);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("Enter the element at (%d, %d): ", &arr[i][j]);
        }
    }

    search(arr, n, target);

    free(arr);

    return 0;
}