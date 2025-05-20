//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int line_num = 0;
    FILE *fp = NULL;

    // Open the file
    fp = fopen("source.c", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read the file line by line
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL)
    {
        // Increment the line number
        line_num++;

        // Remove comments and whitespace
        char *p = buffer;
        while (*p)
        {
            if (*p == '/' && *(p + 1) == '/')
            {
                *p = '\0';
            }
            else if (*p == ' ' && *(p - 1) != '\\')
            {
                *p = '\0';
            }
            p++;
        }

        // Format the line
        char *formatted_line = malloc(MAX_BUFFER_SIZE);
        sprintf(formatted_line, "%d: %s\n", line_num, buffer);

        // Print the line
        printf("%s", formatted_line);

        // Free the memory
        free(formatted_line);
    }

    // Close the file
    fclose(fp);

    return 0;
}