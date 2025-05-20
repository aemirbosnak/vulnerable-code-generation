//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

// Function to split the command into arguments
char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments! Exiting...\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

// Function to execute the command
void execute_command(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        execvp(arguments[0], arguments);
        printf("Error executing command!\n");
        exit(1);
    } else if (pid < 0) {
        // Error forking
        printf("Error forking!\n");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Main function
int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        arguments = split_command(input);
        execute_command(arguments);
    }

    return 0;
}