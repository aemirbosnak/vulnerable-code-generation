//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 1024

typedef struct ShellContext {
    char **history;
    int history_size;
    char prompt[256];
    FILE *fd;
} ShellContext;

ShellContext shell_context;

void shell_init() {
    shell_context.history = NULL;
    shell_context.history_size = 0;
    shell_context.prompt[0] = '$';
    shell_context.prompt[1] = '\0';
    shell_context.fd = stdin;
}

void shell_prompt() {
    printf("%s ", shell_context.prompt);
}

void shell_read_line(char **line) {
    *line = malloc(MAX_CMD_LEN);
    fgets(*line, MAX_CMD_LEN, shell_context.fd);
}

void shell_history_add(char *line) {
    shell_context.history = realloc(shell_context.history, (shell_context.history_size + 1) * sizeof(char *));
    shell_context.history[shell_context.history_size++] = line;
}

void shell_execute(char *line) {
    char **args = NULL;
    char *cmd = strtok(line, " ");

    while (cmd) {
        args = realloc(args, (shell_context.history_size + 1) * sizeof(char *));
        args[shell_context.history_size] = cmd;
        shell_context.history_size++;
        cmd = strtok(NULL, " ");
    }

    // Execute commands
    for (int i = 0; args[i] != NULL; i++) {
        system(args[i]);
    }

    free(args);
}

int main() {
    shell_init();

    char *line = NULL;

    while (1) {
        shell_prompt();
        shell_read_line(&line);
        shell_history_add(line);
        shell_execute(line);
        free(line);
    }

    return 0;
}