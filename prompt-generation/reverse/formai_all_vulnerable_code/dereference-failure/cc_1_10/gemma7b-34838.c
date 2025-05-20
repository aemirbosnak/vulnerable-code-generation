//Gemma-7B DATASET v1.0 Category: Data mining ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char **arr = NULL;
    int i, j, size = 0, count = 0, flag = 0;
    char query[100];

    // Allocate memory dynamically for the array
    arr = (char **)malloc(MAX_SIZE * sizeof(char *));

    // Read the number of lines from the input file
    printf("Enter the number of lines in the file: ");
    scanf("%d", &size);

    // Read the lines from the input file
    for (i = 0; i < size; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
        printf("Enter the line %d: ", i + 1);
        scanf("%[^\n]%*c", arr[i]);
    }

    // Store the query
    printf("Enter your query: ");
    scanf("%s", query);

    // Search for the query in the lines
    for (i = 0; i < size; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (strcmp(query, arr[i][j]) == 0)
            {
                count++;
                flag = 1;
            }
        }
    }

    // Print the results
    if (flag)
    {
        printf("The query '%s' was found in %d lines.\n", query, count);
    }
    else
    {
        printf("The query '%s' was not found.\n", query);
    }

    // Free the memory allocated for the array
    for (i = 0; i < size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}