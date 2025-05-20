//Gemma-7B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = NULL;
    int n = 0, i, j, k, l, found = 0;
    char query[100];

    arr = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("Enter the query: ");
    scanf("%s", query);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(arr[i]); j++)
        {
            if (strstr(arr[i], query) != NULL)
            {
                found = 1;
            }
        }
    }

    if (found)
    {
        printf("Element found: %s\n", arr[i]);
    }
    else
    {
        printf("Element not found\n");
    }

    free(arr);
    return 0;
}