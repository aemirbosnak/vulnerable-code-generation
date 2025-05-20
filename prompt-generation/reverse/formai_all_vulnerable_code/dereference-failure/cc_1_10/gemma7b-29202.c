//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void search(int **arr, int n, int target)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                printf("Target found at (%d, %d)\n", i, j);
                return;
            }
        }
    }

    printf("Target not found\n");
}

int main()
{
    int **arr = NULL;
    int n = 0;
    int target = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the target: ");
    scanf("%d", &target);

    search(arr, n, target);

    return 0;
}