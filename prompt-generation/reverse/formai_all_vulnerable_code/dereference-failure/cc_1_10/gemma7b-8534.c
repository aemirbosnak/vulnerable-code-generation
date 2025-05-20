//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, found = 0;
    char **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(10 * sizeof(char));
    }

    printf("Enter the data: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("Enter the search item: ");
    char item[10];
    scanf("%s", item);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (arr[i][j] == item[0])
            {
                found = 1;
                printf("Item found at row %d, column %d\n", i, j);
            }
        }
    }

    if (!found)
    {
        printf("Item not found\n");
    }

    free(arr);

    return 0;
}