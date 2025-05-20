//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, found = 0;
    char **a;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(10 * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the elements: ");
        scanf("%s", a[i]);
    }

    printf("Enter the search element: ");
    scanf("%s", k);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (strcmp(a[i], k) == 0)
            {
                found = 1;
                printf("Element found at index %d, %d\n", i, j);
            }
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}