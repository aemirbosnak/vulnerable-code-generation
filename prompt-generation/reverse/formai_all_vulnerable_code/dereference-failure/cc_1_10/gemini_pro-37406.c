//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 32

void print_prompt() {
    printf("BraveShell> ");
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int status;

    while (1) {
        print_prompt();
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            printf("\n");
            break;
        }

        // Parse the line into arguments
        int argc = 0;
        char *token = strtok(line, " ");
        while (token != NULL && argc < MAX_ARGS) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }

        // Handle special commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (argc != 2) {
                printf("Usage: cd <directory>\n");
            } else {
                if (chdir(args[1]) != 0) {
                    printf("Error: Could not change directory to %s\n", args[1]);
                }
            }
        } else {
            // Fork a child process to execute the command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                if (execvp(args[0], args) == -1) {
                    printf("Error: Could not execute command %s\n", args[0]);
                    exit(EXIT_FAILURE);
                }
            } else if (pid > 0) {
                // Parent process
                waitpid(pid, &status, 0);
            } else {
                // Fork failed
                printf("Error: Could not fork child process\n");
            }
        }
    }

    return 0;
}