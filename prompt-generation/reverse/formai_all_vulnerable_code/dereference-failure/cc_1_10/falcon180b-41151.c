//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function prototypes
char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    printf("Welcome to the Romantic Shell!\n");
    printf("Enter your commands with love and care.\n");

    while (fgets(input_buffer, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        // Remove newline character
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Split input into arguments
        args = split_string(input_buffer);

        // Execute command
        status = execute_command(args);

        // Print prompt again
        printf("Enter your commands with love and care.\n");
    }

    return 0;
}

// Splits a string into an array of strings using the specified delimiter
char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Executes a command and returns its exit status
int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}