//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_SIZE 1024
#define MAX_ARGS 100

void print_prompt() {
    printf("mysh> ");
}

void execute_command(char *input) {
    char *args[MAX_ARGS];
    char *token;
    int i = 0;

    // Tokenize input using space as delimiter
    token = strtok(input, " \n");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; // Null-terminate the list of arguments

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (i < 2) {
            fprintf(stderr, "mysh: cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("mysh: cd");
        }
        return;
    }

    // Create a new process to execute the command
    pid_t pid = fork();

    if (pid < 0) {
        perror("mysh: fork");
        return;
    }
    
    if (pid == 0) { // Child process
        execvp(args[0], args);
        perror("mysh: exec");
        exit(EXIT_FAILURE);
    } else { // Parent process
        wait(NULL); // Wait for the child to finish
    }
}

int main() {
    char input[MAX_CMD_SIZE];

    while (1) {
        print_prompt(); // Print the shell prompt
        if (fgets(input, MAX_CMD_SIZE, stdin) == NULL) {
            perror("mysh: fgets");
            continue; // Continue in case of error
        }

        execute_command(input); // Execute the command entered by the user
    }

    return 0; // This line will never be reached
}