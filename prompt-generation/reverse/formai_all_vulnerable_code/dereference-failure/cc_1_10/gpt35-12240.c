//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

// Define some constants for the program
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

// Define some functions
void print_prompt();
int read_command(char* command);
int parse_command(char* command, char** arguments);

int main() {
    // Variables
    char command[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];

    printf("Welcome to the funny Unix-like shell!\n");

    while(1) {
        // Print prompt
        print_prompt();

        // Read command
        if(read_command(command) < 0) {
            printf("Oops, an unexpected error occurred!\n");
            continue;
        }

        // Parse command
        int num_arguments = parse_command(command, arguments);

        // Handle special commands
        if(num_arguments == 0) {
            printf("Please enter a command!\n");
            continue;
        }

        if(strcmp(arguments[0], "exit") == 0) {
            printf("Goodbye, shell-enthusiast!\n");
            break;
        }

        // Execute command
        pid_t pid = fork();
        if(pid < 0) {
            printf("Oops, an unexpected error occurred!\n");
            continue;
        }

        if(pid == 0) {
            // Child process
            if(execvp(arguments[0], arguments) < 0) {
                printf("Oops, something went wrong: %s\n", strerror(errno));
                exit(1);
            }
        } else {
            // Parent process
            int status;
            if(waitpid(pid, &status, 0) < 0) {
                printf("Oops, an unexpected error occurred!\n");
            }
        }
    }

    return 0;
}

void print_prompt() {
    printf("Funny-SHELL> ");
}

int read_command(char* command) {
    if(fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
        return -1;
    }

    // Remove trailing newline character
    command[strcspn(command, "\n")] = '\0';

    return 0;
}

int parse_command(char* command, char** arguments) {
    // Variables
    int num_arguments = 0;

    // Parse command
    char* argument = strtok(command, " ");
    while(argument != NULL) {
        if(num_arguments >= MAX_ARGUMENTS - 1) {
            printf("Too many arguments!\n");
            break;
        }

        arguments[num_arguments++] = argument;

        argument = strtok(NULL, " ");
    }

    // Set last argument to NULL
    arguments[num_arguments] = NULL;

    return num_arguments;
}