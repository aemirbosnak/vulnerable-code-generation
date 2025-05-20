//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int i, j, n, m, found = 0;
    char **arr;

    // Allocate memory
    arr = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the elements
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    // Get the search element
    printf("Enter the search element: ");
    scanf("%s", &m);

    // Search for the element
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (strcmp(arr[i], m) == 0)
            {
                found = 1;
                break;
            }
        }
    }

    // Print the result
    if (found)
    {
        printf("Element found.\n");
    }
    else
    {
        printf("Element not found.\n");
    }

    // Free memory
    for (i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}