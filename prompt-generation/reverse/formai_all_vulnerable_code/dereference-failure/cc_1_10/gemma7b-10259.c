//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024

typedef struct CmdLine {
    char *cmd_line;
    char **argv;
    int argc;
} CmdLine;

CmdLine *parse_cmd_line(char *line) {
    CmdLine *cmd_line = malloc(sizeof(CmdLine));
    cmd_line->cmd_line = strdup(line);
    cmd_line->argv = NULL;
    cmd_line->argc = 0;

    char *arg_start = strchr(line, ' ');
    if (arg_start) {
        cmd_line->argv = malloc((arg_start - line) / sizeof(char *) + 1);
        cmd_line->argc = arg_start - line + 1;
        memcpy(cmd_line->argv, line, arg_start - line);
    }

    return cmd_line;
}

int main() {
    char line[MAX_CMD_LEN];

    printf("Enter a command: ");
    fgets(line, MAX_CMD_LEN, stdin);

    CmdLine *cmd_line = parse_cmd_line(line);

    if (cmd_line->argc > 0) {
        printf("Command: %s\n", cmd_line->argv[0]);
        printf("Arguments: ");
        for (int i = 1; i < cmd_line->argc; i++) {
            printf("%s ", cmd_line->argv[i]);
        }
        printf("\n");
    } else {
        printf("Invalid command.\n");
    }

    free(cmd_line->argv);
    free(cmd_line);

    return 0;
}