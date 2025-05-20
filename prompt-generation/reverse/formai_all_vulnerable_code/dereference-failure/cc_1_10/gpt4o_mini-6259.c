//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

// Function prototypes
void execute_command(char *input);
char **parse_input(char *input);
void free_arguments(char **args);

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("myshell> "); // Prompt
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets error");
            continue;
        }

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0;

        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            break;
        }

        execute_command(input);
    }
    return 0;
}

void execute_command(char *input) {
    char **args = parse_input(input);
    if (args[0] == NULL) {
        free_arguments(args);
        return; // No command entered
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        free_arguments(args);
        return;
    }

    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec error");
        }
        exit(EXIT_FAILURE); // Exit child process if exec fails
    } else { // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child to finish
    }

    free_arguments(args);
}

char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    if (!args) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    char *token;
    int position = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        args[position++] = token;
        token = strtok(NULL, " ");
    }
    args[position] = NULL; // Null terminate the list of arguments
    return args;
}

void free_arguments(char **args) {
    free(args); // Free the memory allocated for arguments
}