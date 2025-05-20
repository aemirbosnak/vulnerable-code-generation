//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_NUM_ARGS 100
#define HIST_SIZE 100

typedef struct {
    char command[MAX_CMD_LENGTH];
    int execution_count;
} CommandHistory;

CommandHistory history[HIST_SIZE];
int history_count = 0;

void add_to_history(const char *command) {
    for (int i = 0; i < history_count; i++) {
        if (strcmp(history[i].command, command) == 0) {
            history[i].execution_count++;
            return;
        }
    }
    if (history_count < HIST_SIZE) {
        strcpy(history[history_count].command, command);
        history[history_count].execution_count = 1;
        history_count++;
    } else {
        // Overwrite the oldest command in history
        strcpy(history[0].command, command);
        history[0].execution_count = 1;
    }
}

void display_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%s - Executed %d times\n", history[i].command, history[i].execution_count);
    }
}

void execute_command(char *cmd) {
    char *args[MAX_NUM_ARGS];
    char *token = strtok(cmd, " \n");
    int i = 0;

    while (token != NULL && i < MAX_NUM_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "history") == 0) {
        display_history();
        return;
    }

    add_to_history(cmd);

    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Execute command in child process
        execvp(args[0], args);
        perror("Execution failed"); // Only reached if exec fails
        exit(1);
    } else {
        // Parent process waits for child to finish
        wait(NULL);
    }
}

int main() {
    char cmd[MAX_CMD_LENGTH];

    printf("Welcome to MyStatShell! Type 'exit' to quit, 'history' to view command history.\n");

    while (1) {
        printf("myshell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            perror("Failed to read command");
            continue;
        }
        
        if (strlen(cmd) > 0) {
            execute_command(cmd);
        }
    }

    return 0;
}