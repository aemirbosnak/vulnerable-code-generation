//Gemma-7B DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    char **data = NULL;
    int i, j, k, l, size = 0;
    char query[1024];

    // Allocate memory for the data
    data = (char **)malloc(MAX_SIZE * sizeof(char *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        data[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Read data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp)
    {
        while (!feof(fp))
        {
            getline(data[size], MAX_SIZE, fp);
            size++;
        }
        fclose(fp);
    }

    // Store the query
    printf("Enter your query: ");
    scanf("%s", query);

    // Search for the query in the data
    for (i = 0; i < size; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            if (strstr(data[i], query) != NULL)
            {
                printf("Document %d: %s\n", i + 1, data[i]);
            }
        }
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}