//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_HISTORY 10
#define MAX_ARGS 100

char *history[MAX_HISTORY];
int history_count = 0;

void add_to_history(char *cmd) {
    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(cmd);
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(cmd);
    }
}

void print_history() {
    printf("Command History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}

char **parse_command(char *cmd) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *arg = strtok(cmd, " \n");
    int index = 0;

    while (arg != NULL && index < MAX_ARGS - 1) {
        args[index++] = arg;
        arg = strtok(NULL, " \n");
    }
    args[index] = NULL;
    return args;
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Shell Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork Error");
    } else {
        wait(NULL);
    }
}

int main() {
    char command[MAX_CMD_LENGTH];

    while (1) {
        printf("myshell> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        add_to_history(command);
        if (strncmp(command, "history", 7) == 0) {
            print_history();
            continue;
        }

        char **args = parse_command(command);
        if (args[0] == NULL) {
            free(args);
            continue;
        }

        execute_command(args);
        free(args);
    }

    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
    return 0;
}