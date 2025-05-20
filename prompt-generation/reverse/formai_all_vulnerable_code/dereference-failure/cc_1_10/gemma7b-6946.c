//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 256

char **parse_command(char **cmd)
{
    int i = 0;
    char **args = NULL;
    char *arg = NULL;

    while (*cmd[i] != '\0')
    {
        if (*cmd[i] == ' ')
        {
            args = realloc(args, (i + 1) * sizeof(char *));
            arg = malloc(MAX_CMD_LEN);
            args[i] = arg;
            i++;
        }
        else
        {
            arg = realloc(arg, MAX_CMD_LEN);
            *arg = *cmd[i];
            i++;
        }
    }

    args = realloc(args, (i + 1) * sizeof(char *));
    args[i] = NULL;

    return args;
}

int main()
{
    char cmd[MAX_CMD_LEN];

    printf("Enter command: ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char **args = parse_command(&cmd);

    if (args)
    {
        for (int i = 0; args[i] != NULL; i++)
        {
            printf("Arg: %s\n", args[i]);
        }
    }

    return 0;
}