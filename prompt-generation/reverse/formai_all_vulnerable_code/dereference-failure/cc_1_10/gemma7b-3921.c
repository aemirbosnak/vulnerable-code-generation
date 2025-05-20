//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 255

char **parse_cmd(char **argv, char **cmd_line)
{
    int i = 0, cmd_len = 0;
    char **cmd_argv = NULL;

    *cmd_line = malloc(MAX_CMD_LEN);

    printf("prompt$ ");
    getline(*cmd_line, MAX_CMD_LEN, stdin);

    cmd_len = strlen(*cmd_line);

    if (cmd_len)
    {
        cmd_argv = malloc((cmd_len + 1) * sizeof(char *));

        for (i = 0; i < cmd_len; i++)
        {
            if (*((*cmd_argv) = strchr(*cmd_line, ' ')) != NULL)
            {
                *cmd_argv++ = NULL;
                *cmd_line = strchr(*cmd_line, ' ') + 1;
            }
            else
            {
                cmd_argv++;
            }
        }

        *cmd_argv = NULL;
    }

    return cmd_argv;
}

int main()
{
    char **cmd_line = NULL;
    char **cmd_argv = NULL;

    while (1)
    {
        cmd_argv = parse_cmd(&cmd_line, cmd_line);

        if (cmd_argv)
        {
            execvp(cmd_argv[0], cmd_argv);
        }
    }

    return 0;
}