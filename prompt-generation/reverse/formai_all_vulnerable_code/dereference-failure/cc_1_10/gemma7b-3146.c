//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CMD_LEN 256

typedef struct CmdLine {
    char **cmd_line;
    int size;
    int capacity;
} CmdLine;

CmdLine *cmd_line_init(int capacity) {
    CmdLine *cmd_line = malloc(sizeof(CmdLine));
    cmd_line->cmd_line = malloc(sizeof(char *) * capacity);
    cmd_line->size = 0;
    cmd_line->capacity = capacity;
    return cmd_line;
}

void cmd_line_add(CmdLine *cmd_line, char *cmd) {
    if (cmd_line->size == cmd_line->capacity) {
        cmd_line->cmd_line = realloc(cmd_line->cmd_line, sizeof(char *) * cmd_line->capacity * 2);
        cmd_line->capacity *= 2;
    }

    cmd_line->cmd_line[cmd_line->size++] = cmd;
}

void cmd_line_print(CmdLine *cmd_line) {
    for (int i = 0; i < cmd_line->size; i++) {
        printf("%s ", cmd_line->cmd_line[i]);
    }
    printf("\n");
}

int main() {
    CmdLine *cmd_line = cmd_line_init(10);

    char cmd[MAX_CMD_LEN];

    printf("Enter command: ");

    fgets(cmd, MAX_CMD_LEN, stdin);

    cmd_line_add(cmd_line, cmd);

    cmd_line_print(cmd_line);

    return 0;
}