//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

int main()
{
    char **lines = NULL;
    int numLines = 0;
    int i = 0;

    lines = malloc(MAX_LINES * sizeof(char *));
    for (int i = 0; i < MAX_LINES; i++)
    {
        lines[i] = malloc(20 * sizeof(char));
    }

    printf("Enter a command: ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "draw") == 0)
    {
        printf("Enter the number of lines: ");
        int numLines = atoi(stdin);

        for (i = 0; i < numLines; i++)
        {
            printf("Enter the line: ");
            scanf("%s", lines[i]);
        }

        for (i = 0; i < numLines; i++)
        {
            printf("%s\n", lines[i]);
        }
    }
    else if (strcmp(command, "clear") == 0)
    {
        for (i = 0; i < numLines; i++)
        {
            free(lines[i]);
        }
        free(lines);
        numLines = 0;
    }

    printf("Thank you for using the text to ASCII art generator.\n");

    return 0;
}