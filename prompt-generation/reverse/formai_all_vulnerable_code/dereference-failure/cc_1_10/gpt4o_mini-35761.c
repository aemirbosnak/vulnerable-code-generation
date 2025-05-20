//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

#define MAX_CMD_SIZE 1024
#define MAX_ARG_SIZE 100
#define MAX_HISTORY 10

char* history[MAX_HISTORY];
int history_count = 0;

void add_to_history(char* command) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void sigchld_handler(int signo) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main() {
    signal(SIGCHLD, sigchld_handler); // Handle child termination

    char command[MAX_CMD_SIZE];
    char* args[MAX_ARG_SIZE];

    while (1) {
        printf("my_shell> ");
        fflush(stdout);

        if (fgets(command, MAX_CMD_SIZE, stdin) == NULL) {
            break; // Exit on EOF
        }

        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (strcmp(command, "history") == 0) {
            print_history();
            continue;
        }

        // Add command to history
        add_to_history(command);

        // Parse command
        int arg_count = 0;
        char* token = strtok(command, " ");
        while (token != NULL && arg_count < MAX_ARG_SIZE - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Handle background execution
        int background = 0;
        if (arg_count > 0 && strcmp(args[arg_count - 1], "&") == 0) {
            background = 1;
            args[arg_count - 1] = NULL; // Remove '&' from args
        }

        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("my_shell");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("my_shell");
        } else {
            // Parent process
            if (!background) {
                waitpid(pid, NULL, 0); // Wait for child process
            }
        }
    }

    // Free history
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }

    return 0;
}