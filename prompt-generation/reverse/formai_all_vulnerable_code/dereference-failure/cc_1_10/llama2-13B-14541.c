//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: active
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

int main(void) {
    struct command *cmd;
    int pid;

    // Example 1: Running a command and capturing its output
    cmd = malloc(sizeof(struct command));
    cmd->name = "ls";
    cmd->args[0] = "-l";
    cmd->args[1] = "-t";
    cmd->args[2] = "/";

    printf("Running command: %s %s %s\n", cmd->name, cmd->args[0], cmd->args[1]);
    pid = fork();
    if (pid == 0) {
        // Child process
        execv(cmd->name, cmd->args);
    } else {
        // Parent process
        wait(NULL);
        printf("Command output: %s\n", cmd->args[2]);
    }

    free(cmd);

    // Example 2: Running a command and redirecting its output to a file
    cmd = malloc(sizeof(struct command));
    cmd->name = "grep";
    cmd->args[0] = "-nH";
    cmd->args[1] = "/etc/passwd";
    cmd->args[2] = "user";

    printf("Running command: %s %s %s\n", cmd->name, cmd->args[0], cmd->args[1]);
    pid = fork();
    if (pid == 0) {
        // Child process
        freopen("output.txt", "w", stdout);
        execv(cmd->name, cmd->args);
    } else {
        // Parent process
        wait(NULL);
        printf("Command output written to output.txt\n");
    }

    free(cmd);

    return 0;
}