//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_for_love(char **arr, int n)
{
    int i, j, found = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                found = 1;
                break;
            }
        }
    }

    if (found)
    {
        printf("Love has been found!\n");
    }
    else
    {
        printf("No love found.\n");
    }
}

int main()
{
    char **arr = NULL;
    int n = 0;

    printf("Enter the number of singles: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Enter the singles' names: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    search_for_love(arr, n);

    return 0;
}