//Gemma-7B DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct CmdLine
{
    char **cmd_line;
    int cmd_line_size;
    int cmd_line_used;
} CmdLine;

void init_cmd_line(CmdLine *cmd_line)
{
    cmd_line->cmd_line = NULL;
    cmd_line->cmd_line_size = 0;
    cmd_line->cmd_line_used = 0;
}

void add_cmd_line(CmdLine *cmd_line, char **cmd_line_arg)
{
    if (cmd_line->cmd_line_used == cmd_line->cmd_line_size)
    {
        int new_size = cmd_line->cmd_line_size * 2;
        cmd_line->cmd_line = realloc(cmd_line->cmd_line, new_size);
        cmd_line->cmd_line_size = new_size;
    }

    cmd_line->cmd_line[cmd_line->cmd_line_used++] = cmd_line_arg;
}

int main()
{
    CmdLine cmd_line;
    init_cmd_line(&cmd_line);

    char **cmd_line_arg = malloc(MAX_CMD_LEN);
    strcpy(cmd_line_arg, "ls -l");

    add_cmd_line(&cmd_line, cmd_line_arg);

    free(cmd_line_arg);

    printf("Commands:\n");
    for (int i = 0; i < cmd_line.cmd_line_used; i++)
    {
        printf("%s\n", cmd_line.cmd_line[i]);
    }

    return 0;
}