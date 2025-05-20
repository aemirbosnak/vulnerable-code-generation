//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100
#define HISTORY_COUNT 10

char *history[HISTORY_COUNT];
int history_index = 0;

void add_to_history(const char *command) {
    if (history_index < HISTORY_COUNT) {
        history[history_index++] = strdup(command);
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_COUNT; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_COUNT - 1] = strdup(command);
    }
}

void print_history() {
    for (int i = 0; i < history_index; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    if ((pid = fork()) == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("exec");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void parse_and_execute(char *input) {
    char *args[MAX_ARGS];
    char *token = strtok(input, " \n");
    int index = 0;

    while (token != NULL && index < MAX_ARGS - 1) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL; // Null-terminate the list of arguments

    if (index == 0) return; // If no command entered

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "history") == 0) {
        print_history();
    } else {
        add_to_history(input);
        execute_command(args);
    }
}

int main() {
    char input[MAX_INPUT];

    printf("Welcome to MyShell! Type 'exit' to quit.\n");

    while (1) {
        printf("myshell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets failed");
            break;
        }
        parse_and_execute(input);
    }

    // Free memory allocated for history
    for (int i = 0; i < history_index; i++) {
        free(history[i]);
    }

    return 0;
}