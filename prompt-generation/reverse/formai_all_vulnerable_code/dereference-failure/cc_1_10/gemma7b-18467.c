//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

char **parse_cmd(char **argv, char **cmd)
{
    char **new_argv = NULL;
    int i = 0;
    int argc = 0;

    *cmd = malloc(MAX_CMD_LEN);
    fgets(*cmd, MAX_CMD_LEN, stdin);

    // Strip newline from command
    char *nl = strchr(*cmd, '\n');
    if (nl)
        *nl = NULL;

    // Tokenize command
    char *token = strtok(*cmd, " ");
    while (token)
    {
        new_argv = realloc(new_argv, (argc + 1) * sizeof(char *));
        new_argv[argc++] = strdup(token);
        token = strtok(NULL, " ");
    }

    // Null-terminate argv
    new_argv[argc] = NULL;

    return new_argv;
}

int main()
{
    char **argv = NULL;
    char **cmd = NULL;

    parse_cmd(&argv, &cmd);

    // Execute command
    execvp(argv[0], argv);

    // Free resources
    free(cmd);
    free(argv);

    return 0;
}