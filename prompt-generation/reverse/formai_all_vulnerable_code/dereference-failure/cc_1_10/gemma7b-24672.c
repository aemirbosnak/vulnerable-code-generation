//Gemma-7B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct Command {
    char **commands;
    int capacity;
    int used;
} Command;

Command *createCommand() {
    Command *cmd = malloc(sizeof(Command));
    cmd->commands = malloc(MAX_CMD_LEN * sizeof(char *));
    cmd->capacity = MAX_CMD_LEN;
    cmd->used = 0;
    return cmd;
}

void addCommand(Command *cmd, char **command) {
    if (cmd->used >= cmd->capacity) {
        return;
    }
    cmd->commands[cmd->used++] = command;
}

int executeCommand(Command *cmd) {
    for (int i = 0; i < cmd->used; i++) {
        printf("%s\n", cmd->commands[i]);
    }
    return 0;
}

int main() {
    Command *cmd = createCommand();
    char **command1 = malloc(20 * sizeof(char));
    command1 = "ls -l";
    addCommand(cmd, command1);

    char **command2 = malloc(20 * sizeof(char));
    command2 = "pwd";
    addCommand(cmd, command2);

    executeCommand(cmd);

    free(command1);
    free(command2);
    free(cmd);

    return 0;
}