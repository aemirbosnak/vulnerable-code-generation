//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define HISTORY_SIZE 10

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(char *cmd) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(cmd);
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(cmd);
    }
}

void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    pid_t pid, wpid;
    int status;

    // Tokenize the command
    char *token = strtok(cmd, " \n");
    int i = 0;
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    // Built-in commands
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
        return;
    }

    // Fork and exec
    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WNOHANG);
        } while (wpid == 0);
    }
}

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("myshell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            perror("Error reading input");
            continue;
        }

        // Add command to history
        add_to_history(cmd);

        execute_command(cmd);
    }

    // Cleanup history
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }

    return 0;
}