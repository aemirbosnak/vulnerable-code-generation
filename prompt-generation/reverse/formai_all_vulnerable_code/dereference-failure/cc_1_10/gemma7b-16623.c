//Gemma-7B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct Cmd {
    char **commands;
    int size;
    int alloc_size;
} Cmd;

Cmd *cmd_alloc(int size)
{
    Cmd *cmd = malloc(sizeof(Cmd));
    cmd->commands = malloc(size * sizeof(char *));
    cmd->size = size;
    cmd->alloc_size = size;
    return cmd;
}

void cmd_add(Cmd *cmd, char **command)
{
    if (cmd->size == cmd->alloc_size)
    {
        cmd->alloc_size *= 2;
        cmd->commands = realloc(cmd->commands, cmd->alloc_size * sizeof(char *));
    }
    cmd->commands[cmd->size++] = command;
}

int main()
{
    Cmd *cmd = cmd_alloc(10);

    char **command1 = malloc(MAX_CMD_LEN);
    strcpy(command1, "ls -l");

    char **command2 = malloc(MAX_CMD_LEN);
    strcpy(command2, "pwd");

    char **command3 = malloc(MAX_CMD_LEN);
    strcpy(command3, "echo hello");

    cmd_add(cmd, command1);
    cmd_add(cmd, command2);
    cmd_add(cmd, command3);

    for (int i = 0; i < cmd->size; i++)
    {
        printf("%s\n", cmd->commands[i]);
    }

    free(command1);
    free(command2);
    free(command3);
    free(cmd);

    return 0;
}