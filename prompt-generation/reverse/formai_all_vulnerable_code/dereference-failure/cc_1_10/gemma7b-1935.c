//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, found = 0;
    char **arr;

    printf("Enter the number of rows and columns:");
    scanf("%d %d", &n, &k);

    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(k * sizeof(char));
    }

    printf("Enter the characters:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%c", &arr[i][j]);
        }
    }

    printf("Enter the character to search for:");
    scanf("%c", &l);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (arr[i][j] == l)
            {
                found = 1;
                printf("Character found at (%d, %d)\n", i, j);
            }
        }
    }

    if (!found)
    {
        printf("Character not found\n");
    }

    free(arr);

    return 0;
}