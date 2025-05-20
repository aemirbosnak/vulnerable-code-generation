//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

struct command {
    char *argv[MAX_ARGS];
    int argc;
};

struct command *parse_command(char *line) {
    struct command *cmd = malloc(sizeof(struct command));
    cmd->argc = 0;

    char *token = strtok(line, " ");
    while (token != NULL) {
        cmd->argv[cmd->argc++] = token;
        token = strtok(NULL, " ");
    }

    return cmd;
}

void execute_command(struct command *cmd) {
    if (cmd->argc == 0) {
        return;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(cmd->argv[0], cmd->argv);
        fprintf(stderr, "Error: execvp failed\n");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        // Error
        fprintf(stderr, "Error: fork failed\n");
    }
}

int main() {
    char line[MAX_LINE_LENGTH];

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        struct command *cmd = parse_command(line);
        execute_command(cmd);

        free(cmd);
    }

    return 0;
}