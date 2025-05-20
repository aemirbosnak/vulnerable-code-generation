//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define HISTORY_SIZE 10

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(const char *cmd) {
    if (history_count < HISTORY_SIZE) {
        history[history_count] = strdup(cmd);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(cmd);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    char *token = strtok(cmd, " \n");
    int i = 0;
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (i == 0) return; // No command

    // Built-in commands
    if (strcmp(args[0], "exit") == 0) {
        free_history();
        exit(0);
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
        return;
    }

    // Create a new process
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Check for I/O redirection
        for (int j = 0; j < i; j++) {
            if (strcmp(args[j], ">") == 0) {
                int fd = open(args[j + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
                if (fd == -1) {
                    perror("Error opening file for writing");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
                args[j] = NULL; // Terminate args here
                break;
            } else if (strcmp(args[j], "<") == 0) {
                int fd = open(args[j + 1], O_RDONLY);
                if (fd == -1) {
                    perror("Error opening file for reading");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
                args[j] = NULL; // Terminate args here
                break;
            }
        }

        // Execute the command
        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
            exit(1);
        }
    } else {
        // Parent process waits for the child
        wait(NULL);
    }
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("myshell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break; // EOF
        }

        add_to_history(cmd);
        execute_command(cmd);
    }

    free_history();
    return 0;
}