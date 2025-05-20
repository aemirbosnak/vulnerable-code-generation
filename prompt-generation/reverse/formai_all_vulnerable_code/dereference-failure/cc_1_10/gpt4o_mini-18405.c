//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGUMENTS 100
#define DELIMITER " \t\r\n\a"

// Function to execute a command using fork and exec
int execute_command(char **arguments) {
    pid_t pid, wpid;
    int status;

    // Create child process
    pid = fork();

    if (pid == -1) { // Error forking
        perror("Failed to fork");
        return -1;
    } else if (pid == 0) { // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("Failed to execute command");
        }
        exit(EXIT_FAILURE); // Exit child process if exec fails
    } else { // Parent process
        do {
            wpid = waitpid(pid, &status, WNOHANG);
            if (wpid == -1) {
                perror("waitpid failed");
                return -1;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

// Function to change the directory
void change_directory(char **arguments) {
    if (arguments[1] == NULL) {
        fprintf(stderr, "cd: Too few arguments\n");
    } else {
        if (chdir(arguments[1]) != 0) {
            perror("cd failed");
        }
    }
}

// Function to display the shell prompt
void display_prompt() {
    printf("myshell> ");
}

// Function to read input from the user
char *read_input() {
    char *input = malloc(MAX_INPUT_SIZE);
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        perror("Failed to read input");
        return NULL;
    }
    return input;
}

// Function to parse the input into arguments
char **parse_input(char *input) {
    int bufsize = MAX_NUM_ARGUMENTS;
    char **arguments = malloc(bufsize * sizeof(char*));
    char *arg;
    int position = 0;

    arg = strtok(input, DELIMITER);
    while (arg != NULL) {
        arguments[position++] = arg;
        if (position >= bufsize) {
            bufsize += MAX_NUM_ARGUMENTS;
            arguments = realloc(arguments, bufsize * sizeof(char*));
        }
        arg = strtok(NULL, DELIMITER);
    }
    arguments[position] = NULL; // Null-terminate the array of arguments
    return arguments;
}

// Main shell loop
void shell_loop() {
    char *input;
    char **arguments;

    do {
        display_prompt();
        input = read_input();
        if (input == NULL) {
            free(input);
            break; // Break loop on input failure
        }
        
        arguments = parse_input(input);
        if (arguments[0] == NULL) {
            free(input);
            free(arguments);
            continue; // Ignore empty input
        }

        if (strcmp(arguments[0], "cd") == 0) {
            change_directory(arguments);
        } else if (strcmp(arguments[0], "exit") == 0) {
            free(input);
            free(arguments);
            break; // Break loop on exit command
        } else {
            execute_command(arguments);
        }

        free(input);
        free(arguments);
    } while (1);
}

// Main entry point of the shell program
int main() {
    shell_loop();
    return 0;
}