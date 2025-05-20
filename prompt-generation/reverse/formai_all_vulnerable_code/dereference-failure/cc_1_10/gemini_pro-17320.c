//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* A simple Unix-like shell that can execute commands. */

int main(int argc, char *argv[]) {
    char *line;
    char *args[10];
    int status;

    while (1) {
        printf("Enter a command: ");
        line = malloc(1024);
        fgets(line, 1024, stdin);
        line[strlen(line) - 1] = 0;

        // Tokenize the command into arguments.
        int num_args = tokenize(line, args, 10);

        // Fork a child process to execute the command.
        int pid = fork();
        if (pid == 0) {
            // Child process.
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if (pid > 0) {
            // Parent process.
            waitpid(pid, &status, 0);
        } else {
            perror("fork");
            exit(1);
        }

        free(line);
    }

    return 0;
}

/* Tokenize a string into an array of arguments. */
int tokenize(char *line, char *args[], int max_args) {
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL && num_args < max_args) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }
    return num_args;
}