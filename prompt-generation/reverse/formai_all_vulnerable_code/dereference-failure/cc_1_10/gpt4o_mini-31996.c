//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_HISTORY 100
#define MAX_ARG_SIZE 100

char *history[MAX_HISTORY];
int history_count = 0;

void add_to_history(char *command) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i-1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
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

void execute_command(char *input) {
    char *args[MAX_ARG_SIZE];
    char *token = strtok(input, " \n");
    int index = 0;

    while (token != NULL && index < MAX_ARG_SIZE - 1) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL;

    if (args[0] == NULL) {
        return; // empty command
    }

    if (strcmp(args[0], "exit") == 0) {
        free_history();
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        }
        return;
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
        return;
    }

    pid_t pid = fork();
    if (pid == 0) { // child
        if (execvp(args[0], args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("shell");
    } else { // parent
        wait(NULL);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("myshell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // end of file or error
        }

        // Add command to history
        add_to_history(input);
        execute_command(input);
    }

    free_history();
    return 0;
}