//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char shell_prompt[] = "shell$ ";

int main()
{
    char cmd[MAX_CMD_LEN];
    char **args;
    int argc;

    while (1)
    {
        printf("%s", shell_prompt);
        fgets(cmd, MAX_CMD_LEN, stdin);

        args = NULL;
        argc = 0;

        // Parse the command line
        char *p = cmd;
        while (*p)
        {
            if (*p == ' ')
            {
                args = realloc(args, (argc + 1) * sizeof(char *));
                args[argc++] = strdup(p);
                p++;
            }
            else
            {
                p++;
            }
        }

        // Execute the command
        if (argc > 0)
        {
            execvp(args[0], args);
        }
        else
        {
            printf("Error: invalid command.\n");
        }

        free(args);
    }

    return 0;
}