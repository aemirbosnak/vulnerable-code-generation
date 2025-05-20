//Gemma-7B DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char **data = NULL;
    int num_records = 0, i, j, k, found = 0;
    char query_string[MAX_SIZE];

    // Allocate memory for the data
    data = (char**)malloc(MAX_SIZE * sizeof(char*));
    for (i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char*)malloc(MAX_SIZE * sizeof(char));
    }

    // Read the data from the file
    FILE* file = fopen("data.txt", "r");
    if (file)
    {
        char line[MAX_SIZE];
        while (fgets(line, MAX_SIZE, file) != NULL)
        {
            strcpy(data[num_records], line);
            num_records++;
        }
        fclose(file);
    }

    // Create the query string
    printf("Enter your query: ");
    scanf("%s", query_string);

    // Search for the query in the data
    for (i = 0; i < num_records; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (strstr(data[i], query_string) != NULL)
            {
                found = 1;
                printf("Record found: %s\n", data[i]);
            }
        }
    }

    // If no record is found
    if (!found)
    {
        printf("No record found.\n");
    }

    // Free the memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}