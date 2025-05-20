//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char line[MAX_LENGTH];
    char *args[MAX_ARGS];
    char *token;
    pid_t pid;
    int status;

    while (1) {
        // Print shell prompt
        printf("$ ");

        // Read command line input
        fgets(line, MAX_LENGTH, stdin);

        // Remove newline character from input
        line[strcspn(line, "\n")] = 0;

        // Tokenize input into arguments
        int idx = 0;
        token = strtok(line, " ");
        while (token != NULL && idx < MAX_ARGS) {
            args[idx++] = token;
            token = strtok(NULL, " ");
        }
        args[idx] = NULL;

        // Check for shell built-in commands
        if (strcmp(args[0], "cd") == 0) {
            // Change directory
            if (args[1] == NULL) {
                // No argument provided, change to home directory
                chdir(getenv("HOME"));
            } else {
                chdir(args[1]);
            }
        } else if (strcmp(args[0], "exit") == 0) {
            // Exit shell
            exit(0);
        } else {
            // Fork new process to execute external command
            pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                exit(0);
            } else if (pid < 0) {
                // Error forking process
                fprintf(stderr, "Error forking process!\n");
                exit(1);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}