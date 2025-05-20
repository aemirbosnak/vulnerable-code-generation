//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024 // Maximum length of command line input
#define MAX_ARGS 64 // Maximum number of arguments in a command
#define PROMPT "mysh> " // Custom prompt 

int execute(char** args); // Function to execute commands
char** parse(char* line); // Function to parse command line input
void cleanup(char** args); // Function to free memory used by arguments

int main() {
    char *line; // Command line input buffer
    char** args; // Array of arguments parsed from command line input
    int status; // Command exit status
    pid_t pid; // PID of forked process

    while(1) {
        printf("%s", PROMPT); // Print custom prompt
        line = malloc(MAX_LENGTH); // Allocate space for command line input
        fgets(line, MAX_LENGTH, stdin); // Read command line input

        if(strcmp(line, "exit\n") == 0) { // Check if user entered "exit"
            exit(0); // Exit program
        }

        args = parse(line); // Parse command line input into array of arguments

        if(args[0] == NULL) { // If no arguments were entered, skip execution
            continue;
        }

        pid = fork(); // Fork process to execute command in new process

        if(pid == 0) { // Child process
            execute(args); // Execute command
            exit(0); // Exit child process
        } else if(pid < 0) { // Fork failed
            printf("Fork failed.\n");
        } else { // Parent process
            waitpid(pid, &status, 0); // Wait for child process to finish
        }

        cleanup(args); // Free memory used by arguments
        free(line); // Free memory used by command line input
    }
}

int execute(char** args) {
    if(execvp(args[0], args) == -1) { // Execute command
        printf("mysh: command not found: %s\n", args[0]); // Print error message if command not found
    }

    return 0;
}

char** parse(char* line) {
    char** args = malloc(MAX_ARGS * sizeof(char*)); // Allocate space for array of arguments
    char* arg; // Temporary argument buffer
    int i = 0; // Counter for number of arguments

    arg = strtok(line, " \t\r\n"); // Parse first argument from input

    while(arg != NULL) {
        args[i] = arg; // Add argument to array
        i++;

        arg = strtok(NULL, " \t\r\n"); // Parse next argument from input
    }

    args[i] = NULL; // Set last argument as NULL for execvp function
    return args;
}

void cleanup(char** args) {
    int i = 0;

    while(args[i] != NULL) { // Free memory used by each argument
        free(args[i]);
        i++;
    }

    free(args); // Free memory used by argument array
}