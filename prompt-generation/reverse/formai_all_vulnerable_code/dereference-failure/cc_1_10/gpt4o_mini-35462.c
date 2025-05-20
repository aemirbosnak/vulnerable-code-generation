//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define MAX_HISTORY 20

// Function declarations
void executeCommand(char *input);
void changeDirectory(char *path);
void printHistory();
void addToHistory(char *command);
void freeHistory();

char *history[MAX_HISTORY];
int historyCount = 0;

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("myshell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Break on Ctrl+D or error
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 0) {
            addToHistory(input);
            executeCommand(input);
        }
    }

    freeHistory();
    return 0;
}

void executeCommand(char *input) {
    char *arguments[MAX_ARGUMENTS];
    char *token = strtok(input, " ");
    int i = 0;

    // Tokenize input
    while (token != NULL && i < MAX_ARGUMENTS - 1) {
        arguments[i++] = token;
        token = strtok(NULL, " ");
    }
    arguments[i] = NULL;

    // Handle built-in commands
    if (strcmp(arguments[0], "cd") == 0) {
        changeDirectory(arguments[1]);
    } else if (strcmp(arguments[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(arguments[0], "history") == 0) {
        printHistory();
    } else {
        // Fork and execute external commands
        pid_t pid = fork();
        if (pid == 0) { // Child process
            if (execvp(arguments[0], arguments) == -1) {
                perror("myshell");
            }
            exit(EXIT_FAILURE); // Exit child process on error
        } else if (pid < 0) {
            perror("myshell");
        } else { // Parent process
            wait(NULL); // Wait for child to finish
        }
    }
}

void changeDirectory(char *path) {
    if (path == NULL || chdir(path) != 0) {
        perror("myshell");
    }
}

void printHistory() {
    for (int i = 0; i < historyCount; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
}

void addToHistory(char *command) {
    if (historyCount < MAX_HISTORY) {
        history[historyCount] = strdup(command);
        historyCount++;
    } else {
        free(history[0]);
        for (int i = 1; i < MAX_HISTORY; i++) {
            history[i - 1] = history[i];
        }
        history[MAX_HISTORY - 1] = strdup(command);
    }
}

void freeHistory() {
    for (int i = 0; i < historyCount; i++) {
        free(history[i]);
    }
}