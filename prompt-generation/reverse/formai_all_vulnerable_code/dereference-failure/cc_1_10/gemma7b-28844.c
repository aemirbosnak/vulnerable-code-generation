//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, found = 0;
    char **arr;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &k);

    arr = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char*)malloc(k * sizeof(char));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("Enter the element you want to search for: ");
    scanf("%c", &l);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (arr[i][j] == l)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("Element found.\n");
    }
    else
    {
        printf("Element not found.\n");
    }

    free(arr);

    return 0;
}