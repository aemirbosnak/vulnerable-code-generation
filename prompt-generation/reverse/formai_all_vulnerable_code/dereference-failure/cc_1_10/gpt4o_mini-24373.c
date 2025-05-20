//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_HISTORY 10

// Function prototypes
void execute_command(char *cmd);
void add_to_history(char *cmd);
void show_history();
void clear_history();

char *history[MAX_HISTORY];
int history_count = 0;

// Main function to start the shell
int main() {
    char input[MAX_INPUT];

    printf("Welcome to Knuth Shell! Type 'exit' to quit.\n");

    while (1) {
        printf("knuth-shell> ");
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets error");
            continue;
        }

        // Remove trailing newline
        input[strcspn(input, "\n")] = 0;

        // Check for empty input
        if (strlen(input) == 0) {
            continue;
        }

        // Command history management
        add_to_history(input);

        // If user wants to show history
        if (strcmp(input, "history") == 0) {
            show_history();
            continue;
        }

        // If user wants to exit
        if (strcmp(input, "exit") == 0) {
            clear_history();
            break;
        }

        // Execute the command
        execute_command(input);
    }

    printf("Exiting Knuth Shell...\n");
    return 0;
}

// Execute the given command
void execute_command(char *cmd) {
    pid_t pid, wpid;
    int status;

    // Split the command string into arguments
    char *args[MAX_INPUT / 2 + 1]; // Command line arguments
    char *token = strtok(cmd, " ");
    int i = 0;

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; // Null-terminate the argument list

    // Handle built-in commands
    if (strcmp(args[0], "cd") == 0) {
        if (i > 1) {
            if (chdir(args[1]) != 0) {
                perror("cd error");
            }
        } else {
            fprintf(stderr, "cd: Missing argument\n");
        }
        return;
    }

    // Fork a child process to execute the command
    if ((pid = fork()) == -1) {
        perror("fork error");
        return;
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec error");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

// Add command to history
void add_to_history(char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count] = strdup(cmd);
        history_count++;
    } else {
        free(history[0]); // Free the oldest command
        memmove(history, history + 1, (MAX_HISTORY - 1) * sizeof(char *));
        history[MAX_HISTORY - 1] = strdup(cmd);
    }
}

// Show command history
void show_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
}

// Clear command history
void clear_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
    history_count = 0;
}