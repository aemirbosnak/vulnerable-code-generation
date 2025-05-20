//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct CmdLine {
    char **cmd_line;
    int cmd_line_size;
    int cmd_line_used;
} CmdLine;

CmdLine *init_cmd_line(int size) {
    CmdLine *cmd_line = malloc(sizeof(CmdLine));
    cmd_line->cmd_line = malloc(size * sizeof(char *));
    cmd_line->cmd_line_size = size;
    cmd_line->cmd_line_used = 0;

    return cmd_line;
}

void add_cmd_line(CmdLine *cmd_line, char *cmd) {
    if (cmd_line->cmd_line_used == cmd_line->cmd_line_size) {
        cmd_line->cmd_line_size *= 2;
        cmd_line->cmd_line = realloc(cmd_line->cmd_line, cmd_line->cmd_line_size * sizeof(char *));
    }

    cmd_line->cmd_line[cmd_line->cmd_line_used++] = cmd;
}

int main() {
    CmdLine *cmd_line = init_cmd_line(MAX_CMD_LEN);

    char cmd[MAX_CMD_LEN];

    printf("Enter a command: ");

    fgets(cmd, MAX_CMD_LEN, stdin);

    add_cmd_line(cmd_line, cmd);

    printf("Here are your commands:\n");

    for (int i = 0; i < cmd_line->cmd_line_used; i++) {
        printf("%s\n", cmd_line->cmd_line[i]);
    }

    free(cmd_line->cmd_line);
    free(cmd_line);

    return 0;
}