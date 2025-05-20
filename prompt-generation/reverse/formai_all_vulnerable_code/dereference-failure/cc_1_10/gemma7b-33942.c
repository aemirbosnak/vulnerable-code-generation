//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void search(int **arr, int n, int target)
{
    int i = 0;
    int j = n - 1;
    int mid = (i + j) / 2;

    while (i <= j)
    {
        if (arr[mid][0] == target)
        {
            printf("Target found at index: (%d, %d)\n", mid, arr[mid][1]);
            return;
        }
        else if (arr[mid][0] < target)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    printf("Target not found\n");
}

int main()
{
    int **arr = NULL;
    int n = 0;
    int target = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    printf("Enter the target: ");
    scanf("%d", &target);

    search(arr, n, target);

    return 0;
}