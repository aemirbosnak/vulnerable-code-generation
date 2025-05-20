//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUMBER_OF_ARGS 10
#define MAX_HISTORY_SIZE 20

char history[MAX_HISTORY_SIZE][MAX_COMMAND_LENGTH];
int historyCount = 0;

void addHistory(char* command) {
    if (strcmp(command, "") != 0) {
        // Shift history entries back by one
        for (int i = historyCount; i > 0; i--) {
            strcpy(history[i], history[i - 1]);
        }

        // Add new entry to history
        strcpy(history[0], command);

        // Increment history count (up to MAX_HISTORY_SIZE)
        historyCount = (historyCount < MAX_HISTORY_SIZE) ? historyCount + 1 : historyCount;
    }
}

void printHistory() {
    printf("Command history:\n");
    for (int i = 0; i < historyCount; i++) {
        printf("  %d: %s\n", i + 1, history[i]);
    }
}

char** parseCommand(char* command) {
    // Allocate space for an array of strings to hold the command and its arguments
    char** args = malloc(MAX_NUMBER_OF_ARGS * sizeof(char*));

    // Initialize each string to null
    for (int i = 0; i < MAX_NUMBER_OF_ARGS; i++) {
        args[i] = NULL;
    }

    // Parse the command into separate arguments
    int argIndex = 0;
    char* token = strtok(command, " ");
    while (token != NULL) {
        args[argIndex] = token;
        argIndex++;
        token = strtok(NULL, " ");

        // Check if we've exceeded the maximum number of arguments
        if (argIndex >= MAX_NUMBER_OF_ARGS) {
            break;
        }
    }

    return args;
}

void executeCommand(char** args) {
    // Fork a child process to execute the command
    pid_t pid = fork();

    if (pid == -1) {
        // Error occurred while forking
        printf("Error: Could not create child process\n");
    } else if (pid == 0) {
        // We're in the child process
        execvp(args[0], args);

        // If we reach this line, the exec call failed (command not found)
        printf("Error: Command not found\n");
        exit(0);
    } else {
        // We're in the parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char exitCommand[] = "exit";
    char historyCommand[] = "history";

    printf("Welcome to MyShell!\n");

    // Loop until the user types "exit"
    while (1) {
        // Prompt the user for a new command
        printf("MyShell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from end of command
        command[strcspn(command, "\n")] = 0;

        // Check for exit command
        if (strcmp(command, exitCommand) == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Check for history command
        if (strcmp(command, historyCommand) == 0) {
            printHistory();
            continue;
        }

        // Add command to history
        addHistory(command);

        // Parse the command
        char** args = parseCommand(command);

        // Execute the command
        executeCommand(args);

        // Free memory allocated for arguments
        free(args);
    }

    return 0;
}