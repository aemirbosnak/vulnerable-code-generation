//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_CMD_HISTORY 10

char *cmd_history[MAX_CMD_HISTORY];
int history_count = 0;

void add_to_history(const char *cmd) {
    if (history_count < MAX_CMD_HISTORY) {
        cmd_history[history_count++] = strdup(cmd);
    } else {
        free(cmd_history[0]);  // Remove the oldest command
        for (int i = 1; i < MAX_CMD_HISTORY; i++) {
            cmd_history[i - 1] = cmd_history[i];
        }
        cmd_history[MAX_CMD_HISTORY - 1] = strdup(cmd);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, cmd_history[i]);
    }
}

void execute_command(char *cmd) {
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("Failed to fork");
        return;
    } else if (pid == 0) {
        char *args[MAX_CMD_LEN / 2 + 1];
        char *token = strtok(cmd, " \n");
        int i = 0;

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL;

        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
        }
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

void change_directory(char *path) {
    if (chdir(path) != 0) {
        perror("cd failed");
    }
}

int main() {
    char cmd[MAX_CMD_LEN];

    while (1) {
        printf("mysh> ");
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            continue;
        }

        if (strcmp(cmd, "exit\n") == 0) {
            break;
        }

        if (strncmp(cmd, "cd ", 3) == 0) {
            change_directory(cmd + 3);
            continue;
        }

        if (strcmp(cmd, "history\n") == 0) {
            print_history();
            continue;
        }

        add_to_history(cmd);
        execute_command(cmd);
    }

    // Free command history
    for (int i = 0; i < history_count; i++) {
        free(cmd_history[i]);
    }

    return 0;
}