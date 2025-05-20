//Gemma-7B DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void main()
{
    char **arr = NULL;
    int i, j, k, n, m, size = 0;
    char query[100];

    printf("Enter the number of lines you want to store: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    printf("Enter the lines: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    printf("Enter your query: ");
    scanf("%s", query);

    m = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (strstr(arr[i], query) != NULL)
            {
                m++;
            }
        }
    }

    printf("The number of lines containing the query is: %d", m);

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return;
}