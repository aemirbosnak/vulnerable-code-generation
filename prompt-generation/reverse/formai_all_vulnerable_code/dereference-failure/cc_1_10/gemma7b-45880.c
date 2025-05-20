//Gemma-7B DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char **arr = NULL;
    int i = 0, j = 0, k = 0, l = 0, n = 0, m = 0, count = 0, flag = 0, found = 0;
    FILE *fp = NULL;

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%d", &n);
    arr = malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        arr[i] = malloc(20 * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s", arr[i]);
    }

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if (arr[i][j] != '\0')
            {
                count++;
            }
        }
    }

    printf("Total number of characters in the file: %d\n", count);

    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return;
}