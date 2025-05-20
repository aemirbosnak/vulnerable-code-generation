//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"
#define MAX_PATH 1024

// Function prototypes
char *get_command(char *line);
char **get_arguments(char *line);
int execute_command(char **args);
int change_directory(char *dir);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    char **arguments;
    int status;

    printf("Welcome to the Basic Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        command = get_command(input);
        arguments = get_arguments(input);
        status = execute_command(arguments);

        if (status == 1) {
            printf("Error: Command not found\n");
        } else if (status == 2) {
            printf("Error: Invalid argument\n");
        } else if (status == 3) {
            printf("Error: Permission denied\n");
        }
    }

    return 0;
}

// Get the command from the input string
char *get_command(char *line) {
    char *command = strtok(line, DELIM);
    return command;
}

// Get the arguments from the input string
char **get_arguments(char *line) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(line, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc] = strdup(token);
        argc++;
        token = strtok(NULL, DELIM);
    }

    arguments[argc] = NULL;
    return arguments;
}

// Execute the command with the given arguments
int execute_command(char **args) {
    int status = 0;

    if (strcmp(args[0], "cd") == 0) {
        status = change_directory(args[1]);
    } else if (strcmp(args[0], "exit") == 0) {
        status = 1;
    } else {
        status = 1;
    }

    return status;
}

// Change the current directory
int change_directory(char *dir) {
    if (chdir(dir)!= 0) {
        printf("Error: Permission denied\n");
        return 3;
    }

    return 0;
}