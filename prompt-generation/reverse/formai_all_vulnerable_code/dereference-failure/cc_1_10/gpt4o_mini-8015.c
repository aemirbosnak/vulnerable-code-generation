//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024   // Maximum size of input
#define MAX_NUM_ARGS 100      // Maximum number of arguments

// Function to execute a command
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();  
    if (pid == -1) {
        perror("fork");
        return;  // Exit if fork fails
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);  
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); 
    }
}

// Function to parse the user input into arguments
void parse_input(char *input, char **args) {
    char *token;
    int index = 0;

    token = strtok(input, " \n");  // Tokenize the input based on space and newline
    while (token != NULL && index < MAX_NUM_ARGS) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL;  // Last argument should be NULL for execvp
}

// Main function to run the shell
int main() {
    char *input = NULL;           // Input line
    char *args[MAX_NUM_ARGS];    // Arguments list
    size_t len = 0;              // Used for getline

    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("> ");  // Prompt for user input
        getline(&input, &len, stdin);  // Read input from user

        if (strcmp(input, "exit\n") == 0) {  // Check for exit
            free(input);
            break; 
        }

        parse_input(input, args);  // Parse the input into arguments

        // If nothing was typed, continue to the next iteration
        if (args[0] == NULL) {
            continue; 
        }

        execute_command(args);  // Execute the command
    }

    return 0;  // Successful termination
}