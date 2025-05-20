//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define MAX_NUM_ARGUMENTS 100
#define HISTORY_SIZE 10

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(char *command) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(command);
    }
}

void show_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void execute_command(char *command) {
    char *args[MAX_NUM_ARGUMENTS];
    char *token = strtok(command, " \n");
    int i = 0;
    while (token != NULL && i < MAX_NUM_ARGUMENTS) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (i < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
    } else if (strcmp(args[0], "history") == 0) {
        show_history();
    } else {
        pid_t pid = fork();
        if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Command execution failed");
            }
            exit(1);
        } else if (pid < 0) {
            perror("Forking failed");
        } else {
            wait(NULL);
        }
    }
}

void prompt() {
    char *buffer = malloc(MAX_COMMAND_LEN);
    while (1) {
        printf("my_shell> ");
        if (fgets(buffer, MAX_COMMAND_LEN, stdin) == NULL) {
            perror("Input failed");
            continue;
        }
        add_to_history(buffer);
        execute_command(buffer);
    }
    free(buffer);
}

int main() {
    prompt();
    return 0;
}