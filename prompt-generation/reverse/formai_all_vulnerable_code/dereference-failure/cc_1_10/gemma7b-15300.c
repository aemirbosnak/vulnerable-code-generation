//Gemma-7B DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 255

typedef struct SystemCommand {
    char **commands;
    int capacity;
    int size;
} SystemCommand;

SystemCommand *createSystemCommand(int capacity) {
    SystemCommand *cmd = malloc(sizeof(SystemCommand));
    cmd->commands = malloc(sizeof(char *) * capacity);
    cmd->capacity = capacity;
    cmd->size = 0;
    return cmd;
}

void addCommand(SystemCommand *cmd, char **command) {
    if (cmd->size == cmd->capacity) {
        return;
    }
    cmd->commands[cmd->size++] = command;
}

int executeCommand(SystemCommand *cmd) {
    for (int i = 0; i < cmd->size; i++) {
        printf("%s\n", cmd->commands[i]);
    }
    return 0;
}

int main() {
    SystemCommand *cmd = createSystemCommand(10);
    char **command1 = malloc(sizeof(char *) * 10);
    command1[0] = "ls";
    command1[1] = "-l";
    addCommand(cmd, command1);

    char **command2 = malloc(sizeof(char *) * 10);
    command2[0] = "pwd";
    command2[1] = "";
    addCommand(cmd, command2);

    executeCommand(cmd);

    free(command1);
    free(command2);
    free(cmd);

    return 0;
}