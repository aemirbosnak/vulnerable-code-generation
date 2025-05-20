//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **haystack = NULL;
    char **needle = NULL;
    int n = 0;
    int i = 0;
    int paranoia = 0;

    printf("Enter the number of items in the haystack: ");
    scanf("%d", &n);

    haystack = (char **)malloc(n * sizeof(char *));
    needle = (char **)malloc(n * sizeof(char *));

    printf("Enter the items in the haystack, separated by commas: ");
    for (i = 0; i < n; i++)
    {
        haystack[i] = (char *)malloc(20 * sizeof(char));
        scanf("%s", haystack[i]);
    }

    printf("Enter the needle item: ");
    needle[0] = (char *)malloc(20 * sizeof(char));
    scanf("%s", needle[0]);

    paranoia = 0;
    while (!paranoia)
    {
        paranoia = 1;
        for (i = 0; i < n; i++)
        {
            if (strcmp(needle[0], haystack[i]) == 0)
            {
                paranoia = 0;
                printf("Item found in haystack item %d.\n", i);
            }
        }

        if (paranoia)
        {
            printf("Item not found.\n");
        }

        printf("Enter 'q' to quit or any other key to continue: ");
        char key;
        scanf("%c", &key);

        if (key == 'q')
        {
            break;
        }
    }

    return 0;
}