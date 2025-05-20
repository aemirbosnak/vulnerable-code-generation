//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64
#define MAX_PROMPT_SIZE 128

void printPrompt(char* prompt) {
    printf("%s ", prompt);
    fflush(stdout);
}

int readInput(char* input) {
    if(fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        return 0;
    }
    // Replace newline character with null terminator
    input[strcspn(input, "\n")] = '\0';
    return 1;
}

void executeCommand(char** args, int numArgs) {
    int pid, status;
    pid = fork();
    if(pid < 0) {
        printf("fork failed\n");
        exit(1);
    } else if(pid == 0) {
        // Child process
        execvp(args[0], args);
        printf("command not found: %s\n", args[0]);
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

int tokenizeInput(char* input, char** args, char* delims) {
    int numArgs = 0;
    char* token = strtok(input, delims);
    while(token != NULL) {
        args[numArgs++] = strdup(token);
        token = strtok(NULL, delims);
    }
    return numArgs;
}

int main() {
    char input[MAX_INPUT_SIZE];
    char* args[MAX_ARGS];
    char prompt[MAX_PROMPT_SIZE] = "admin@system:";
    int numArgs;

    while(1) {
        printPrompt(prompt);
        if(readInput(input) == 0) {
            break;
        }
        numArgs = tokenizeInput(input, args, " ");
        if(numArgs > 0) {
            executeCommand(args, numArgs);
        }
        // Free memory used for storing arguments
        for(int i = 0; i < numArgs; i++) {
            free(args[i]);
        }
    }

    return 0;
}