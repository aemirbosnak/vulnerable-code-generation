//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0;

    // Get the source code from the user
    printf("Enter source code: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Remove comments and whitespace
    char* p = strstr(buffer, "//");
    while (p)
    {
        char* q = strchr(p, '\n');
        if (q)
        {
            *q = '\0';
        }
        else
        {
            p = NULL;
        }
    }

    // Indent the lines
    p = buffer;
    while (*p)
    {
        int line_length = 0;
        char* q = strchr(p, '\n');
        if (q)
        {
            line_length = q - p;
        }
        else
        {
            line_length = strlen(p);
        }
        for (int i = 0; i < line_length; i++)
        {
            printf("%c ", ' ');
        }
        printf("%s\n", p);
        p = q;
    }

    return 0;
}