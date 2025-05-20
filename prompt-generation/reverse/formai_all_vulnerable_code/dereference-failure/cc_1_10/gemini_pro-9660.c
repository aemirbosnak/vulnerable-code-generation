//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    char *args[MAX_ARGS];
    int num_args;
    int status;

    while (1) {
        printf("myshell> ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Parse the command line into arguments
        num_args = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (num_args < 2) {
                printf("Usage: cd <directory>\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("chdir");
                }
            }
        } else {
            // Fork a child process to execute the command
            pid_t pid = fork();
            if (pid < 0) {
                perror("fork");
            } else if (pid == 0) {
                // Child process
                if (execvp(args[0], args) == -1) {
                    perror("execvp");
                    exit(1);
                }
            } else {
                // Parent process
                wait(&status);
            }
        }
    }

    return 0;
}