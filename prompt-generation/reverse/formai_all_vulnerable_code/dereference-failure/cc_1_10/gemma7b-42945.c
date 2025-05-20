//Gemma-7B DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char **data = NULL;
    int i, j, k, size = 0;
    char query[20];

    // Allocating memory for the data
    data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Reading data
    printf("Enter the data (separate entries with a newline):\n");
    for (i = 0; data[i] != NULL && gets(data[i]) != NULL; i++)
    {
        size++;
    }

    // Storing the data
    for (i = 0; i < size; i++)
    {
        printf("%s\n", data[i]);
    }

    // Searching for a query
    printf("Enter your query:\n");
    gets(query);

    // Comparing the query with each entry in the data
    for (i = 0; i < size; i++)
    {
        if (strstr(data[i], query) != NULL)
        {
            printf("%s\n", data[i]);
        }
    }

    // Freeing memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}