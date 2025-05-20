//Gemma-7B DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    char **arr = NULL;
    int i, j, n, k, l, count = 0, found = 0;

    arr = (char **)malloc(MAX * sizeof(char *));

    for (i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    n = 0;

    while (1)
    {
        printf("Enter data: ");
        scanf("%s", arr[n]);

        if (strcmp(arr[n], "end") == 0)
        {
            break;
        }

        n++;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                k = strcmp(arr[i], arr[j]);

                if (k == 0)
                {
                    count++;
                }
            }
        }
    }

    if (count > 0)
    {
        printf("Number of duplicates: %d\n", count);
    }
    else
    {
        printf("No duplicates found.\n");
    }

    for (i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}