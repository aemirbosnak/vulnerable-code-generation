//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 512
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split(char *str, char delimiter) {
    int count = 0;
    char *token = strtok(str, delimiter);
    char **tokens = (char **) malloc((count + 1) * sizeof(char *));

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

// Function to execute a command and return its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command found.\n");
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

// Main function to parse and execute commands
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Split input into command and arguments
        args = split(input, DELIM);

        // Execute command and print its exit status
        status = execute_command(args);
        printf("Exit status: %d\n", status);
    }

    return 0;
}