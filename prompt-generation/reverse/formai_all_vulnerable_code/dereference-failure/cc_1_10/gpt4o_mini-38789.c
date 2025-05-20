//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100
#define HISTORY_SIZE 10

char *history[HISTORY_SIZE];
int history_count = 0;

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else {
        // Parent process
        wait(NULL);
    }
}

void add_to_history(char *command) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(command);
    }
}

void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_SIZE];

    while (1) {
        printf("mysh> ");
        fflush(stdout);

        // Read input
        if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
            break; // Exit on end-of-file (Ctrl+D)
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        // Check for empty input
        if (strlen(input) == 0) {
            continue;
        }

        // Check for built-in command
        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "history") == 0) {
            print_history();
            continue;
        }

        // Add command to history
        add_to_history(input);

        // Tokenize the input
        int arg_count = 0;
        char *token = strtok(input, " ");
        while (token && arg_count < MAX_ARG_SIZE - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; // Null terminate the args array

        // Execute the command
        execute_command(args);
    }

    // Free allocated memory for history
    free_history();
    return 0;
}