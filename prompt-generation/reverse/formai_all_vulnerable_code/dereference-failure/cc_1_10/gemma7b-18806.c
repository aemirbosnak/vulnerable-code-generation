//Gemma-7B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Command {
    char **commands;
    int size;
    int alloc_size;
} Command;

Command *command_init(int size) {
    Command *cmd = malloc(sizeof(Command));
    cmd->commands = malloc(size * sizeof(char *));
    cmd->size = size;
    cmd->alloc_size = size;
    return cmd;
}

void command_add(Command *cmd, char **command) {
    if (cmd->size == cmd->alloc_size) {
        cmd->commands = realloc(cmd->commands, (cmd->alloc_size + 1) * sizeof(char *));
        cmd->alloc_size++;
    }
    cmd->commands[cmd->size++] = command;
}

int main() {
    Command *commands = command_init(10);
    char **command_list = malloc(10 * sizeof(char *));

    command_list[0] = "ls";
    command_list[1] = "pwd";
    command_list[2] = "echo hello";
    command_list[3] = "mkdir myfolder";

    for (int i = 0; i < 4; i++) {
        command_add(commands, command_list[i]);
    }

    for (int i = 0; i < commands->size; i++) {
        printf("%s\n", commands->commands[i]);
    }

    free(commands->commands);
    free(commands);
    free(command_list);

    return 0;
}