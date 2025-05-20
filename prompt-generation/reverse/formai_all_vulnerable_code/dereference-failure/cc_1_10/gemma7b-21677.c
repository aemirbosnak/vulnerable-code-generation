//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>

void searching(int **arr, int n)
{
    int i, j, key, found = 0;
    printf("Enter the key to search for: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == key)
            {
                found = 1;
                printf("Key found at (%d, %d)\n", i, j);
            }
        }
    }

    if (!found)
    {
        printf("Key not found\n");
    }
}

int main()
{
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    searching(arr, n);

    return 0;
}