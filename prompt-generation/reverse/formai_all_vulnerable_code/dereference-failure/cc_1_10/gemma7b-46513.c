//Gemma-7B DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char **data = NULL;
    int size = 0;
    char query[1024];

    // Allocate memory for the data
    data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Read data from the file
    FILE *file = fopen("data.txt", "r");
    if (file)
    {
        int i = 0;
        char line[MAX_SIZE];
        while (fgets(line, MAX_SIZE, file) != NULL)
        {
            strcpy(data[i], line);
            i++;
        }
        fclose(file);
    }

    // Store the query
    printf("Enter your query: ");
    scanf("%s", query);

    // Search for the query in the data
    for (int i = 0; i < size; i++)
    {
        if (strstr(data[i], query) != NULL)
        {
            printf("Document %d: %s\n", i + 1, data[i]);
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}