//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

struct command {
    char *name;
    char *args[MAX_ARGS];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    struct command *cmd = malloc(sizeof(struct command));
    cmd->name = argv[1];

    int i = 2;
    while (i < argc) {
        cmd->args[i - 2] = argv[i];
        i++;
    }

    // Check if the command exists
    if (access(cmd->name, X_OK) == -1) {
        printf("Command %s not found\n", cmd->name);
        return 2;
    }

    // Execute the command
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execv(cmd->name, cmd->args);
        perror("execv");
        exit(1);
    } else {
        // Parent process
        wait(NULL);
    }

    free(cmd);
    return 0;
}