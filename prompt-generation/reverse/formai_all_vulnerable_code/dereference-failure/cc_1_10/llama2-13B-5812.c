//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define MAX_LINE_LEN 1024
#define MAX_ARGS 10

// Function to print a line to the console
void print_line(const char* line) {
    printf("%s\n", line);
}

// Function to print an error message and exit the program
void error(const char* message) {
    printf("Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Function to read a line from the console and store it in a buffer
char* read_line() {
    char* line = malloc(MAX_LINE_LEN);
    printf("> ");
    fgets(line, MAX_LINE_LEN, stdin);
    return line;
}

// Function to execute a command and print the output
void execute(const char* command) {
    int status;
    char* output = malloc(MAX_LINE_LEN);
    char* args[MAX_ARGS];

    // Split the command into arguments
    char* token = strtok(command, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    // Execute the command and store the output in the output buffer
    if (execvp(args[0], args) == -1) {
        error("Failed to execute command");
    }
    else {
        wait(&status);
        print_line(output);
    }

    free(output);
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    // Print a welcome message
    print_line("Welcome to the dynamic C programming example!");

    // Read a line from the console and execute it as a command
    char* line = read_line();
    execute(line);

    // Loop indefinitely to read and execute commands
    while (1) {
        // Read a line from the console
        line = read_line();

        // Execute the command and print the output
        execute(line);
    }

    return 0;
}