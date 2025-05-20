//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: standalone
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
    int pid, status;
    char *cmd;
    struct command *c;

    // Example 1: Run a command and capture its output
    cmd = "ls -l /";
    c = malloc(sizeof(struct command));
    c->name = cmd;
    c->args[0] = NULL;

    if ((pid = fork()) < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        execvp(cmd, c->args);
        perror("execvp failed");
        exit(1);
    }

    wait(&status);
    printf("Command output: %s\n", c->args[0]);

    // Example 2: Run a command and redirect its output to a file
    cmd = "echo Hello World > output.txt";
    c = malloc(sizeof(struct command));
    c->name = cmd;
    c->args[0] = NULL;

    if ((pid = fork()) < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        execvp(cmd, c->args);
        perror("execvp failed");
        exit(1);
    }

    wait(&status);
    printf("Command output written to file\n");

    // Example 3: Run a command with arguments
    cmd = "grep 'Hello' input.txt";
    c = malloc(sizeof(struct command));
    c->name = cmd;
    c->args[0] = "input.txt";
    c->args[1] = NULL;

    if ((pid = fork()) < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        execvp(cmd, c->args);
        perror("execvp failed");
        exit(1);
    }

    wait(&status);
    printf("Command output: %s\n", c->args[0]);

    return 0;
}