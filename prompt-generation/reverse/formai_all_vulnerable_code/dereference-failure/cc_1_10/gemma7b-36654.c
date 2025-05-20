//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main()
{
    char **lines = NULL;
    int line_num = 0;

    // Allocate memory for the lines
    lines = malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++)
    {
        lines[i] = malloc(200);
    }

    // Read the lines from the input
    printf("Enter a line: ");
    lines[line_num] = malloc(200);
    getline(stdin, lines[line_num], 200);
    line_num++;

    // Format the lines
    for (int i = 0; lines[i] != NULL; i++)
    {
        // Remove unnecessary whitespace
        char *p = lines[i];
        char *q = lines[i];
        while (p && *p && (*p == ' ' || *p == '\t'))
        {
            p++;
        }
        lines[i] = q;

        // Add indentation for the first line
        if (i == 0)
        {
            lines[i] = strcat(lines[i], "\t");
        }

        // Print the line
        printf("%s\n", lines[i]);
    }

    // Free the memory
    for (int i = 0; lines[i] != NULL; i++)
    {
        free(lines[i]);
    }
    free(lines);

    return 0;
}