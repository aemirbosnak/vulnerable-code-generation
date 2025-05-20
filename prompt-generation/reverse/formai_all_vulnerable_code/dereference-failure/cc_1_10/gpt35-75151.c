//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_ARGS 100

void execute(char **args) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else {
        // Parent process
        int status;
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int argc;
    
    while (1) {
        // Print prompt and get input
        printf("$ ");
        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        input[strcspn(input, "\n")] = '\0'; // remove newline character
        
        // Parse input into arguments
        argc = 0;
        args[argc] = strtok(input, " ");
        while (args[argc] != NULL && argc < MAX_ARGS - 1) {
            argc++;
            args[argc] = strtok(NULL, " ");
        }
        args[argc] = NULL; // set last argument to NULL
        
        // Check for exit command
        if (strcmp(args[0], "exit") == 0) {
            exit(EXIT_SUCCESS);
        }
        
        // Execute command
        execute(args);
    }
    
    return 0;
}