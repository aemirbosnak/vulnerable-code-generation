//Falcon-180B DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

// Function to split a command into arguments
char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc] = strdup(token);
        argc++;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

// Function to execute a command and wait for it to finish
void execute_command(char **arguments) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(arguments[0], arguments);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        // Error forking
        perror("fork");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **arguments = split_command(input);
    execute_command(arguments);

    return 0;
}