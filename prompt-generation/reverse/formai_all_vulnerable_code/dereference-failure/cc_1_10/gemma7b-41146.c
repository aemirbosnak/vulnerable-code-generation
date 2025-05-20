//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 1024

int main()
{
    char cmd[MAX_CMD_LEN];
    char **argv;
    int argc;
    int i;

    while (1)
    {
        printf("$ ");
        fgets(cmd, MAX_CMD_LEN, stdin);

        // Parse the command line
        argc = parse_cmd(cmd, &argv);

        // Execute the command
        if (argc > 0)
        {
            for (i = 0; i < argc; i++)
            {
                printf("argv[%d] = %s\n", i, argv[i]);
            }

            execvp(argv[0], argv);
        }
    }

    return 0;
}

int parse_cmd(char *cmd, char ***argv)
{
    char *ptr;
    int argc = 0;

    // Allocate memory for argv
    *argv = malloc(MAX_CMD_LEN * sizeof(char *));

    // Split the command into tokens
    ptr = strtok(cmd, " ");
    while (ptr)
    {
        (*argv)[argc++] = ptr;
        ptr = strtok(NULL, " ");
    }

    return argc;
}