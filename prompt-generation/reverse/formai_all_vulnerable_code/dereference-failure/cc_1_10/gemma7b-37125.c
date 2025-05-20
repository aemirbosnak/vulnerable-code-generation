//Gemma-7B DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct CmdLine
{
    char **cmd_line;
    int size;
    int alloc_size;
} CmdLine;

CmdLine *create_cmd_line(int size)
{
    CmdLine *cmd_line = malloc(sizeof(CmdLine));
    cmd_line->cmd_line = malloc(size * sizeof(char *));
    cmd_line->size = size;
    cmd_line->alloc_size = size;

    return cmd_line;
}

void add_cmd_line(CmdLine *cmd_line, char *cmd)
{
    if (cmd_line->size == cmd_line->alloc_size)
    {
        cmd_line->alloc_size *= 2;
        cmd_line->cmd_line = realloc(cmd_line->cmd_line, cmd_line->alloc_size * sizeof(char *));
    }

    cmd_line->cmd_line[cmd_line->size++] = cmd;
}

int main()
{
    CmdLine *cmd_line = create_cmd_line(10);

    add_cmd_line(cmd_line, "ls");
    add_cmd_line(cmd_line, "pwd");
    add_cmd_line(cmd_line, "echo hello");

    for (int i = 0; i < cmd_line->size; i++)
    {
        printf("%s\n", cmd_line->cmd_line[i]);
    }

    free(cmd_line->cmd_line);
    free(cmd_line);

    return 0;
}