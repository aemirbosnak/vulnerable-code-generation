//Gemma-7B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char **arr = NULL;
    int i, j, k, n, m, l;

    // Allocate memory
    arr = (char **)malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    // Fill the array with random text
    n = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            arr[i][j] = (rand() % 26) + 97;
        }
        arr[i][20] = '\0';
        n++;
    }

    // Find the longest word in the array
    l = 0;
    for (i = 0; i < n; i++)
    {
        m = strlen(arr[i]);
        if (m > l)
        {
            l = m;
        }
    }

    // Print the longest word
    for (i = 0; i < n; i++)
    {
        if (strlen(arr[i]) == l)
        {
            printf("%s\n", arr[i]);
        }
    }

    // Free memory
    for (i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}