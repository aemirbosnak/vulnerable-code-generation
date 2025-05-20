//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void beautifier(char *);

int main()
{
    char *str = "This is a string that will be beautified.\nIt has some interesting content and I want to make it look better.";

    beautifier(str);

    printf("%s", str);

    return 0;
}

void beautifier(char *str)
{
    // Split the string into lines
    char **lines = NULL;
    int numLines = 0;
    char *line = str;
    while (line)
    {
        lines = realloc(lines, (numLines + 1) * sizeof(char *));
        lines[numLines++] = line;
        line = strchr(line, '\n');
    }

    // Indent each line
    for (int i = 0; i < numLines; i++)
    {
        int indent = 0;
        char *p = lines[i];
        while (p && p[0] == ' ')
        {
            indent++;
            p++;
        }
        for (int j = 0; j < indent; j++)
        {
            lines[i] = strcat(lines[i], " ");
        }
    }

    // Join the lines back into a string
    str = "";
    for (int i = 0; i < numLines; i++)
    {
        str = strcat(str, lines[i]);
        if (i < numLines - 1)
        {
            str = strcat(str, "\n");
        }
    }

    // Free the memory allocated for lines
    free(lines);
}