//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Split a string into an array of strings using delimiter
char **split_string(char *str, char delim) {
    int count = 0;
    char **tokens = malloc(MAX_COMMAND_LENGTH * sizeof(char*));
    char *token = strtok(str, delim);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delim);
    }

    tokens[count] = NULL;
    return tokens;
}

// Execute a command and return its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

// Main shell loop
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Linus Torvalds Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input, '\n');
        execute_command(args);

        free(args);
    }

    return 0;
}