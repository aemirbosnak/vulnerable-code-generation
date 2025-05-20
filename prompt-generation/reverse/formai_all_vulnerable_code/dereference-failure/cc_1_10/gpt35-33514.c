//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
#define TOKEN_DELIMITER " \t\r\n\a"

// Function declarations
void shell_loop(void);
char *read_input(void);
char **parse_input(char *input);
void execute_command(char **args);

// Main function
int main(int argc, char **argv) {
    // Call the shell loop function
    shell_loop();

    return EXIT_SUCCESS;
}

// Shell loop function
void shell_loop(void) {
    char *input;
    char **args;
    int status;

    do {
        // Print the command prompt
        printf(">> ");

        // Read the command from user input
        input = read_input();

        // Parse the command into arguments
        args = parse_input(input);

        // Execute the command
        execute_command(args);

        // Free dynamically allocated memory
        free(input);
        free(args);
    } while (status != -1);
}

// Read user input from the command line
char *read_input(void) {
    char *input = NULL;
    size_t buffer_size = 0;
    getline(&input, &buffer_size, stdin);
    return input;
}

// Parse user input into separate arguments
char **parse_input(char *input) {
    char **args = malloc(BUFFER_SIZE * sizeof(char*));
    char *token;
    int i = 0;

    // Check for allocation error
    if (args == NULL) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, TOKEN_DELIMITER);

    // Parse tokens from input string and store them in the args array
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, TOKEN_DELIMITER);
    }

    // Null terminate the array of arguments
    args[i] = NULL;

    return args;
}

// Execute the command typed by the user
void execute_command(char **args) {
    pid_t pid;
    int status;

    // Fork a new process
    pid = fork();

    if (pid == 0) {
        // Child process: execute the command
        if (execvp(args[0], args) == -1) {
            perror("Execution error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Forking error
        perror("Fork error");
    } else {
        // Parent process: wait for child to finish executing
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}