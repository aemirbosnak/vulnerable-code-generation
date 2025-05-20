//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_SIZE 1024
#define MAX_NUM_ARGS 100

void executeCommand(char** parsedCommand) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        if (execvp(parsedCommand[0], parsedCommand) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE); // Terminate child process if execvp fails
    } else if (pid < 0) {
        perror("Fork failed");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child process to finish
    }
}

void parseInput(char* input, char** parsedCommand) {
    char* token;
    int index = 0;

    token = strtok(input, " \n");
    while (token != NULL && index < MAX_NUM_ARGS - 1) {
        parsedCommand[index++] = token;
        token = strtok(NULL, " \n");
    }
    parsedCommand[index] = NULL; // Null-terminate the command array
}

int main() {
    char* input = NULL;
    char* parsedCommand[MAX_NUM_ARGS];
    
    // Dynamic memory allocation for input
    input = (char*)malloc(MAX_COMMAND_SIZE * sizeof(char));
    if (input == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    printf("Surprised Shell! Type your command (%s to exit):\n", "exit");

    while (1) {
        printf(">>> ");
        if (fgets(input, MAX_COMMAND_SIZE, stdin) == NULL) {
            perror("Error reading input");
            continue;
        }

        // Handle exit command
        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting surprised shell! Bye!\n");
            break;
        }

        parseInput(input, parsedCommand);
        
        printf("You entered: %s", input);
        printf("Executing command: %s\n", parsedCommand[0]);
        
        executeCommand(parsedCommand);
        
        printf("Surprise! Command executed!\n");
    }

    free(input); // Free allocated memory
    return 0;
}