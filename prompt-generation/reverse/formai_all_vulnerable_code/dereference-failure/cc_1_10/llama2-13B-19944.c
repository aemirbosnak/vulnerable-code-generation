//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: modular
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

void execute_command(struct command *cmd) {
    int status;
    char *cmd_str = NULL;

    // Build the command string
    cmd_str = malloc(sizeof(cmd->name) + sizeof(cmd->args[0]) * MAX_ARGS);
    sprintf(cmd_str, "%s %s", cmd->name, cmd->args[0]);

    // Execute the command
    if (execv(cmd_str, cmd->args) == -1) {
        perror("execv");
        exit(1);
    }

    // Wait for the command to finish
    wait(&status);

    free(cmd_str);
}

int main(void) {
    struct command commands[] = {
        {"ls", {"-l", "/"} },
        {"cd", {"/home"} },
        {"pwd", {NULL, 0} }
    };

    int i;

    for (i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        execute_command(&commands[i]);
    }

    return 0;
}