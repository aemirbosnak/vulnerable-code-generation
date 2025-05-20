//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARG_LENGTH 100
#define MAX_ARGS 100

void executeCommand(char *input) {
    char *args[MAX_ARGS];
    int argCount = 0;

    // Tokenize the input command
    char *token = strtok(input, " \n");
    while (token != NULL && argCount < MAX_ARGS - 1) {
        args[argCount++] = token;
        token = strtok(NULL, " \n");
    }
    args[argCount] = NULL; // Last argument must be NULL for execvp

    // Handle built-in commands
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (argCount < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
        return;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return;
    } else if (pid == 0) {
        // In the child process
        if (execvp(args[0], args) < 0) {
            perror("exec failed");
            exit(1);
        }
    } else {
        // In the parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

void shellLoop() {
    char input[MAX_CMD_LENGTH];
    
    while (1) {
        printf("myshell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF
        }
        executeCommand(input); // Process the command
    }
}

int main() {
    printf("Welcome to MyShell!\n");
    shellLoop();
    return 0;
}