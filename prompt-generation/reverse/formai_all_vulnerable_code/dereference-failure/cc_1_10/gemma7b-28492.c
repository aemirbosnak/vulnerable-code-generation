//Gemma-7B DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    // Declare variables
    char **data = NULL;
    int num_records = 0, i, j, k, l, found = 0;
    char query[MAX];

    // Allocate memory for data
    data = (char**)malloc(MAX * sizeof(char*));
    for(i = 0; i < MAX; i++)
    {
        data[i] = (char*)malloc(MAX * sizeof(char));
    }

    // Read data from file
    FILE* file = fopen("data.txt", "r");
    if(file)
    {
        char line[MAX];
        while(fgets(line, MAX, file) != NULL)
        {
            strcpy(data[num_records], line);
            num_records++;
        }
        fclose(file);
    }

    // Print data
    for(i = 0; i < num_records; i++)
    {
        printf("%s\n", data[i]);
    }

    // Get the query from the user
    printf("Enter your query: ");
    scanf("%s", query);

    // Search for the query in the data
    for(i = 0; i < num_records; i++)
    {
        if(strstr(data[i], query) != NULL)
        {
            found = 1;
            printf("Record found: %s\n", data[i]);
        }
    }

    // If no record is found, print an error message
    if(!found)
    {
        printf("No record found.\n");
    }

    // Free memory
    for(i = 0; i < MAX; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}