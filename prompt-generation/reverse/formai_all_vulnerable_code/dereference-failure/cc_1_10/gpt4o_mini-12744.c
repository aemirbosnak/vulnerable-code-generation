//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_ARGS 100
#define MAX_HISTORY 50

char *history[MAX_HISTORY];
int history_count = 0;

void execute_command(char **args);
void add_to_history(char *input);
void print_history();
void free_history();

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_NUM_ARGS];

    while (1) {
        printf("mysh> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets failed");
            continue;
        }

        // Remove newline character from the input
        input[strcspn(input, "\n")] = 0;

        // Add to history
        add_to_history(input);

        // Parse the input into arguments
        char *token = strtok(input, " ");
        int arg_count = 0;

        while (token != NULL && arg_count < MAX_NUM_ARGS - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL; // Null-terminate the argument list

        // Handle built-in commands
        if (arg_count == 0) {
            continue; // No command entered
        }
        
        if (strcmp(args[0], "exit") == 0) {
            free_history();
            break;
        } else if (strcmp(args[0], "history") == 0) {
            print_history();
            continue;
        }

        // Fork process to execute command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            continue;
        } else if (pid == 0) { // Child process
            execvp(args[0], args);
            perror("exec failed");
            exit(EXIT_FAILURE); // If exec fails, exit child
        } else { // Parent process
            waitpid(pid, NULL, 0); // Wait for child to finish
        }
    }
    return 0;
}

void execute_command(char **args) {
    // Not used; kept for possible future feature expansions
}

void add_to_history(char *input) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(input);
    } else {
        free(history[0]); // Free the oldest entry
        memmove(history, history + 1, (MAX_HISTORY - 1) * sizeof(char *));
        history[MAX_HISTORY - 1] = strdup(input);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
}

void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}