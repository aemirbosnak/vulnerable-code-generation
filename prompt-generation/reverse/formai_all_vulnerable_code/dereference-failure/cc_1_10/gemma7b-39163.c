//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, n, m, search_key, found = 0;
    char **arr;

    printf("Welcome to the futuristic search engine, Matrix Omega.\n");
    printf("Please enter the number of rows and columns you want for the matrix:");
    scanf("%d %d", &n, &m);

    arr = (char **)malloc(n * sizeof(char *) + m * sizeof(char));
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(m * sizeof(char));
    }

    printf("Enter the elements of the matrix:");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c ", &arr[i][j]);
        }
    }

    printf("Enter the key you want to search for:");
    scanf("%d", &search_key);

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == search_key)
            {
                found = 1;
                printf("Key found at: (%d, %d)\n", i, j);
            }
        }
    }

    if (!found)
    {
        printf("Key not found.\n");
    }

    free(arr);

    return 0;
}