//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    char *args[MAX_ARGS];
    int status;
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);
        if (feof(stdin)) {
            break;
        }

        // Parse the line into arguments
        int num_args = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        // Check for built-in commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "cd") == 0) {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        } else {
            // Fork a new process to execute the command
            pid = fork();
            if (pid == 0) {
                // Child process
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else if (pid > 0) {
                // Parent process
                waitpid(pid, &status, 0);
            } else {
                perror("fork");
            }
        }
    }

    return 0;
}