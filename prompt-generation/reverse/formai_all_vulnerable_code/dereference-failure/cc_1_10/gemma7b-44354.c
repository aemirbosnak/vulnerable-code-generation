//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **cmd, int *argc, char ***argv)
{
    *argc = 0;
    *argv = NULL;

    char *cmd_ptr = *cmd;
    char **argv_ptr = NULL;

    while (*cmd_ptr)
    {
        char *arg = strchr(cmd_ptr, ' ');

        if (arg)
        {
            *argv_ptr = malloc(MAX_CMD_LEN);
            memcpy((*argv_ptr++), cmd_ptr, arg - cmd_ptr);
            *argc++;
        }
        else
        {
            *argv_ptr = malloc(MAX_CMD_LEN);
            memcpy((*argv_ptr++), cmd_ptr, strlen(cmd_ptr) + 1);
            *argc++;
            *argv = argv_ptr - 1;
        }

        cmd_ptr = arg ? arg + 1 : NULL;
    }

    return argv;
}

int main()
{
    char cmd[MAX_CMD_LEN];

    printf("$ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    int argc;
    char ***argv = parse_cmd(cmd, &argc, &argv);

    if (argc)
    {
        // Execute command
        execvp(argv[0], argv);
    }
    else
    {
        printf("Invalid command.\n");
    }

    return 0;
}