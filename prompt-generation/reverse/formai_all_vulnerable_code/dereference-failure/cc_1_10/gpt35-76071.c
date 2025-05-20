//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 10
#define MAX_HISTORY 20

char *history[MAX_HISTORY]; // To store the command history
int history_cnt = 0; // Count of commands in history

/**
 * Print the list of previous commands
 */
void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_cnt; i++) {
        printf("%d: %s\n", i+1, history[i]);
    }
}

/**
 * Parse the input command and return the command with arguments
 */
void parse_command(char *cmd, char **args) {
    // Split the command into arguments
    char *arg = strtok(cmd, " ");
    int i = 0;
    while (arg != NULL && i < MAX_ARGS-1) {
        args[i] = arg;
        arg = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL; // Terminate the list of arguments
}

/**
 * Execute the command with arguments
 */
void execute_cmd(char **args) {
    pid_t pid = fork();
    if (pid == -1) { // If fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("exec");
            exit(EXIT_FAILURE);
        }
    } else { // Parent process
        waitpid(pid, NULL, 0);
    }
}

int main() {
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];

    while (1) {
        printf("> ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = 0; // Remove the newline character

        // Add the command to history
        history[history_cnt] = (char*) malloc(strlen(cmd)+1);
        strcpy(history[history_cnt], cmd);
        history_cnt++;
        if (history_cnt > MAX_HISTORY) {
            free(history[0]); // Free the oldest command in history
            for (int i = 0; i < MAX_HISTORY-1; i++) {
                history[i] = history[i+1]; // Shift the commands up in history
            }
            history_cnt--;
        }

        // Check if the user wants to see the list of previous commands
        if (strcmp(cmd, "history") == 0) {
            print_history();
            continue;
        }

        // Parse the command and execute it
        parse_command(cmd, args);
        execute_cmd(args);
    }
    return 0;
}