//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024

// Function to read user input
char* read_input() {
    char* buffer = NULL;
    ssize_t buffer_size = 0;
    getline(&buffer, &buffer_size, stdin);
    return buffer;
}

// Function to parse user input and separate into arguments
char** parse_input(char* input) {
    int buffer_size = MAX_BUFFER, position = 0;
    char** arguments = malloc(buffer_size * sizeof(char*));
    char* argument;

    argument = strtok(input, " \t\r\n\a");
    while (argument != NULL) {
        arguments[position] = argument;
        position++;

        if (position >= buffer_size) {
            buffer_size += MAX_BUFFER;
            arguments = realloc(arguments, buffer_size * sizeof(char*));
        }

        argument = strtok(NULL, " \t\r\n\a");
    }
    arguments[position] = NULL;
    return arguments;
}

// Function to execute a command
int execute_command(char** arguments) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();
    if (pid == 0) {  // Child process
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {  // Failed to fork
        perror("Error forking");
    } else {  // Parent process
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

// Main loop
void shell_loop() {
    char* input;
    char** arguments;
    int status;

    do {
        printf("> ");
        input = read_input();
        arguments = parse_input(input);
        status = execute_command(arguments);

        free(input);
        free(arguments);
    } while (status);
}

// Main function
int main() {
    printf("Welcome to Shell Island!\n");
    shell_loop();
    return EXIT_SUCCESS;
}