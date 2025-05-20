//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

/* Function declarations */
void runShell();

int main() {
    runShell();
    return 0;
}

/* Function that runs the shell */
void runShell() {
    char input[MAX_LENGTH]; // Variable to store user input
    char *args[MAX_ARGS]; // Array of arguments
    
    while(1) {
        printf("> "); // Print shell prompt
        fgets(input, MAX_LENGTH, stdin); // Get user input
        
        /* Tokenize input into individual arguments */
        char *tok = strtok(input, " \n");
        int argCount = 0;
        while(tok != NULL && argCount < MAX_ARGS - 1) {
            args[argCount] = tok;
            tok = strtok(NULL, " \n");
            argCount++;
        }
        args[argCount] = NULL; // Set last argument to NULL for execvp
        
        if(strcmp(args[0], "exit") == 0) {
            exit(0); // Exit shell if user types "exit"
        } else {
            pid_t pid = fork(); // Fork child process
            if(pid == -1) {
                perror("Fork failed");
            } else if(pid == 0) {
                /* Child process */
                if(execvp(args[0], args) == -1) {
                    perror("Execvp failed");
                    exit(1);
                }
            } else {
                /* Parent process */
                int status;
                if(waitpid(-1, &status, 0) == -1) {
                    perror("Waitpid failed");
                }
            }
        }
    }
}