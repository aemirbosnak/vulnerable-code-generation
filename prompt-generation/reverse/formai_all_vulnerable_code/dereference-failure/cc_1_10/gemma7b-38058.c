//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ShellState {
    char **history;
    int historySize;
    char prompt;
    int isInteractive;
    char **args;
    int argPos;
} ShellState;

ShellState shellState;

void shellPrompt() {
    printf("%c", shellState.prompt);
    fflush(stdout);
}

void parseArgs() {
    shellState.args = malloc(MAX_BUFFER_SIZE);
    shellState.argPos = 0;
    char **p = shellState.args;
    char line[MAX_BUFFER_SIZE];
    printf("%c", shellState.prompt);
    scanf("%[^\n]%*c", line);
    char *tok = strtok(line, " ");
    while (tok) {
        *p++ = strdup(tok);
        tok = strtok(NULL, " ");
    }
    *p = NULL;
}

int main() {
    shellState.history = NULL;
    shellState.historySize = 0;
    shellState.prompt = '$';
    shellState.isInteractive = 1;
    shellState.args = NULL;
    shellState.argPos = 0;

    while (shellState.isInteractive) {
        shellPrompt();
        parseArgs();

        // Execute command
        system(shellState.args[0]);

        // Add command to history
        shellState.history = realloc(shellState.history, (shellState.historySize + 1) * sizeof(char *));
        shellState.history[shellState.historySize++] = shellState.args[0];

        // Clear args
        free(shellState.args);
        shellState.args = NULL;
    }

    return 0;
}