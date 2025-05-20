//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARG_LENGTH 100
#define MAX_ARGS 10
#define HISTORY_SIZE 10

// Function prototypes
void execute_command(char **args);
void display_prompt();
void handle_signal(int signal);
void add_to_history(char *command);
void display_history();

char *history[HISTORY_SIZE];
int history_count = 0;

int main() {
    char input[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    
    // Set signal handler for SIGINT
    signal(SIGINT, handle_signal);
    
    while (1) {
        display_prompt();
        
        // Read input from user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets failed");
            continue;
        }
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Add command to history
        add_to_history(input);

        // Tokenize input
        char *token = strtok(input, " ");
        int arg_index = 0;
        while (token != NULL && arg_index < MAX_ARGS - 1) {
            args[arg_index++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_index] = NULL;  // Null-terminate the argument list

        // Check for exit command
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        } else if (strcmp(args[0], "history") == 0) {
            display_history();
            continue;
        }

        // Execute command
        execute_command(args);
    }

    // Free allocated history memory
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }

    return 0;
}

void display_prompt() {
    printf("simple-shell> ");
}

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("\nReceived SIGINT. Use 'exit' to quit.\n");
        display_prompt();
    }
}

void add_to_history(char *command) {
    if (history_count < HISTORY_SIZE) {
        history[history_count] = strdup(command);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(command);
    }
}

void display_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    }
    
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
        }
        exit(EXIT_FAILURE);  // Exit child process if exec fails
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }
}