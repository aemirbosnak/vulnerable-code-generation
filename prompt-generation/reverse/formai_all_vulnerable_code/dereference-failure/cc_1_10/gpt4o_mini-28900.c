//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define MAX_NUM_ARGS 10

void executeCommand(char **args);
void changeDirectory(char *path);
void parseCommand(char *cmd, char **args);
int isBuiltInCommand(char **args);
void handlePipes(char *input);

int main() {
    char command[MAX_CMD_LEN];

    while (1) {
        printf("myshell> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            perror("Error reading command");
            continue;
        }

        // Remove newline character from input
        command[strcspn(command, "\n")] = 0;

        if (strlen(command) == 0) {
            continue; // Ignore empty commands
        }

        // Handle pipes in command
        handlePipes(command);
    }

    return 0;
}

void handlePipes(char *input) {
    char *pipe_cmds[MAX_NUM_ARGS];
    char *cmd = strtok(input, "|");
    int pipe_count = 0;

    while (cmd != NULL) {
        pipe_cmds[pipe_count++] = cmd;
        cmd = strtok(NULL, "|");
    }
    pipe_cmds[pipe_count] = NULL;

    int fd[2], in_fd = 0;

    for (int i = 0; i < pipe_count; i++) {
        pipe(fd);

        if (fork() == 0) {
            dup2(in_fd, 0); // Get input from the previous command
            if (i < pipe_count - 1) {
                dup2(fd[1], 1); // Send output to the pipe
            }
            close(fd[0]);
            char *args[MAX_ARG_LEN];
            parseCommand(pipe_cmds[i], args);
            if (isBuiltInCommand(args)) {
                exit(0);
            }
            execvp(args[0], args);
            perror("Execution failed");
            exit(1);
        } else {
            wait(NULL); // Wait for child process to finish
            close(fd[1]);
            in_fd = fd[0]; // Save input for next command
        }
    }
}

void parseCommand(char *cmd, char **args) {
    while (*cmd != '\0') {
        // Skip leading spaces
        while (*cmd == ' ') cmd++;
        if (*cmd == '\0') break;

        // Extracting an argument
        args[0] = cmd;
        int arg_count = 0;

        while (*cmd != '\0' && *cmd != ' ') {
            if (arg_count < MAX_NUM_ARGS - 1) {
                cmd++;
                arg_count++;
            }
        }
        *cmd = '\0'; // Null-terminate the current argument
        cmd++; // Move past the null terminator
        args[++arg_count] = NULL; // Null-terminate the args list
    }
}

int isBuiltInCommand(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        changeDirectory(args[1]);
        return 1; // Built-in command
    }
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }
    return 0; // Not a built-in command
}

void changeDirectory(char *path) {
    if (path == NULL) {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }
    if (chdir(path) != 0) {
        perror("cd failed");
    }
}

void executeCommand(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        // Parent process
        wait(NULL);
    }
}