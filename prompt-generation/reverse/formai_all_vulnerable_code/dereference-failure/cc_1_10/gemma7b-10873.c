//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void parse_resume(char **resume)
{
    int i = 0;
    char *name = NULL;
    char *position = NULL;
    char *summary = NULL;

    // Allocate memory for the resume
    resume = (char **)malloc(MAX * sizeof(char *));

    // Iterate over the resume
    for (i = 0; resume[i] != NULL; i++)
    {
        // Search for the name, position, and summary sections
        if (strstr(resume[i], "Name:") != NULL)
        {
            name = strtok(resume[i], ":");
            name = strdup(name);
        }
        else if (strstr(resume[i], "Position:") != NULL)
        {
            position = strtok(resume[i], ":");
            position = strdup(position);
        }
        else if (strstr(resume[i], "Summary:") != NULL)
        {
            summary = strtok(resume[i], ":");
            summary = strdup(summary);
        }
    }

    // Print the name, position, and summary
    printf("Name: %s\n", name);
    printf("Position: %s\n", position);
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(resume);
}

int main()
{
    char **resume = NULL;

    // Parse the resume
    parse_resume(resume);

    return 0;
}