//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define MAX_HISTORY 10

char *history[MAX_HISTORY];
int history_count = 0;

void add_history(char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count] = strdup(cmd);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(cmd);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void clear_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
        history[i] = NULL;
    }
    history_count = 0;
}

void execute_command(char *cmd) {
    char *args[MAX_ARG_LEN];
    int i = 0;
    args[i] = strtok(cmd, " \n");  // Tokenize the command
    while (args[i] != NULL && i < MAX_ARG_LEN - 1) {
        i++;
        args[i] = strtok(NULL, " \n");
    }
    
    if (args[0] == NULL) return;  // Empty command

    // Handle built-in commands
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
        return;
    } else if (strcmp(args[0], "clear") == 0) {
        clear_history();
        return;
    }

    // Fork and execute the command
    pid_t pid = fork();
    if (pid == 0) {  // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(1);  // Exit child process if exec fails
    } else if (pid > 0) {  // Parent process
        wait(NULL);  // Wait for child process to finish
    } else {
        perror("Fork failed");
    }
}

int main() {
    char command[MAX_CMD_LEN];

    printf("Welcome to Retro Shell! Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        // Read command from user
        if (fgets(command, MAX_CMD_LEN, stdin) == NULL) {
            break;  // End on error or EOF
        }
        
        add_history(command);  // Store command in history
        execute_command(command);  // Execute the command
    }

    // Clean up history before exiting
    clear_history();
    return 0;
}