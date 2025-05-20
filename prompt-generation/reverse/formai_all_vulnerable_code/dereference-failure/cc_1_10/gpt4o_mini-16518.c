//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGUMENTS 100
#define MAX_HISTORY 10

char *history[MAX_HISTORY];
int history_count = 0;

// Function to add a command to history
void add_to_history(const char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count] = strdup(cmd);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i-1] = history[i];
        }
        history[MAX_HISTORY-1] = strdup(cmd);
    }
}

// Function to print the command history
void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

// Function to free command history
void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

// Main shell function
int main() {
    char input[MAX_INPUT_SIZE];
    char *arguments[MAX_NUM_ARGUMENTS];
    pid_t pid;
    int status;

    // Main shell loop
    while (1) {
        printf("simple_shell> ");
        if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
            break; // Exit on EOF (CTRL+D)
        }

        // Remove trailing newline character from input
        input[strcspn(input, "\n")] = 0;

        // Ignore empty command
        if (strlen(input) == 0) {
            continue;
        }

        // Add command to history
        add_to_history(input);

        // Tokenize the input command
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_NUM_ARGUMENTS) {
            arguments[i++] = token;
            token = strtok(NULL, " ");
        }
        arguments[i] = NULL; // Null terminate the argument list

        // Check for 'exit' command
        if (strcmp(arguments[0], "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // Check for 'history' command
        if (strcmp(arguments[0], "history") == 0) {
            print_history();
            continue;
        }

        // Create a new process for command execution
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            continue;
        } else if (pid == 0) {
            // Child process
            if (execvp(arguments[0], arguments) == -1) {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }

    free_history(); // Free command history before exiting
    return 0;
}