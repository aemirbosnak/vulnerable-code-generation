//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// Function to split a string into an array of strings
char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

// Function to execute a command and wait for it to finish
void execute_command(char **tokens) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

// Function to handle input and execute commands
void handle_input(char *input) {
    char **tokens = split_string(input);
    if (tokens[0] == NULL) {
        // Empty input
        return;
    }
    execute_command(tokens);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }
    return 0;
}