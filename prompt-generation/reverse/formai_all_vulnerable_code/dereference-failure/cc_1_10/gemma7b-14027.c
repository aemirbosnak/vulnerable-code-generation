//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct CmdLine {
    char **argv;
    char **history;
    int idx;
    int max_idx;
} CmdLine;

CmdLine *cmd_line_init(int max_size) {
    CmdLine *cmd_line = malloc(sizeof(CmdLine));
    cmd_line->argv = malloc(max_size * sizeof(char *));
    cmd_line->history = malloc(max_size * sizeof(char *));
    cmd_line->idx = 0;
    cmd_line->max_idx = max_size;
    return cmd_line;
}

void cmd_line_add_arg(CmdLine *cmd_line, char *arg) {
    cmd_line->argv[cmd_line->idx++] = arg;
}

void cmd_line_add_history(CmdLine *cmd_line, char *cmd) {
    cmd_line->history[cmd_line->idx++] = cmd;
}

int main() {
    CmdLine *cmd_line = cmd_line_init(10);

    char cmd[MAX_CMD_LEN];

    printf("Shell prompt: $ ");
    fgets(cmd, MAX_CMD_LEN, stdin);

    char **args = NULL;
    char *arg = strtok(cmd, " ");
    while (arg) {
        cmd_line_add_arg(cmd_line, arg);
        arg = strtok(NULL, " ");
    }

    cmd_line_add_history(cmd_line, cmd);

    printf("Command: %s\n", cmd_line->argv[0]);
    printf("Arguments: ");
    for (int i = 1; cmd_line->argv[i] != NULL; i++) {
        printf("%s ", cmd_line->argv[i]);
    }
    printf("\n");

    return 0;
}