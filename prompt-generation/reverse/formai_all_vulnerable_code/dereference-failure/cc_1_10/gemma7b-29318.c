//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void ShockedSearching(int **arr, int n)
{
    int i, j, target, found = 0;
    printf("OMG! You're in the Shocked Searching algorithm!\n");
    printf("Please enter the target number: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                found = 1;
                printf("FOUND IT! The target number is: %d\n", target);
                break;
            }
        }
    }

    if (!found)
    {
        printf("OMG! The target number is not found!\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
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

    ShockedSearching(arr, n);

    return 0;
}