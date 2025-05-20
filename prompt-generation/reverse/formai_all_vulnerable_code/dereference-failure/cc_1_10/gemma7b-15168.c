//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char **buffer = NULL;
    int buffer_size = 0;
    char line[MAX_BUFFER_SIZE];
    FILE *fp = fopen("data.csv", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the buffer dynamically
    buffer = malloc(buffer_size * sizeof(char *));

    // Read the file line by line
    while (fgets(line, MAX_BUFFER_SIZE, fp) != NULL)
    {
        // Increment the buffer size if necessary
        if (buffer_size == 0)
        {
            buffer_size = 1;
            buffer = realloc(buffer, buffer_size * sizeof(char *));
        }

        // Add the line to the buffer
        buffer[buffer_size - 1] = strdup(line);
        buffer_size++;
    }

    // Close the file
    fclose(fp);

    // Print the buffer
    for (int i = 0; i < buffer_size - 1; i++)
    {
        printf("%s\n", buffer[i]);
    }

    // Free the memory
    free(buffer);

    return 0;
}