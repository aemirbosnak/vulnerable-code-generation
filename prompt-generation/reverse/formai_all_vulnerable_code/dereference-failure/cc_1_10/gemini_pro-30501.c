//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char *args[MAX_ARGS];
    char line[MAX_LINE_LENGTH];

    while (1) {
        printf("osh> ");
        fgets(line, MAX_LINE_LENGTH, stdin);

        // Parse the command line into arguments.
        int num_args = 0;
        char *p = strtok(line, " ");
        while (p != NULL && num_args < MAX_ARGS) {
            args[num_args++] = p;
            p = strtok(NULL, " ");
        }
        args[num_args] = NULL;

        // Check if the command is built-in.
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        } else if (strcmp(args[0], "cd") == 0) {
            if (num_args < 2) {
                fprintf(stderr, "cd: missing operand\n");
            } else {
                if (chdir(args[1]) != 0) {
                    fprintf(stderr, "cd: %s: No such file or directory\n", args[1]);
                }
            }
        } else {
            // Fork a child process to execute the command.
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                fprintf(stderr, "%s: command not found\n", args[0]);
                exit(1);
            } else {
                // Wait for the child process to finish.
                int status;
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}