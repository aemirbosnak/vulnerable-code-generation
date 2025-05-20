//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER 1024
#define MAX_ARGS 64

int main() {
    char buffer[MAX_BUFFER]; 
    char *args[MAX_ARGS]; 
    pid_t pid; 
    int status;

    printf("Unix Shell Example Program\n"); 

    while (1) { 
        printf("Enter a command: "); 
        fgets(buffer, MAX_BUFFER, stdin);

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Split input into arguments
        int i = 0;
        args[i] = strtok(buffer, " ");

        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // Exit program if command is "exit"
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Execute command in child process
        pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            printf("Command not found\n");
            exit(1);
        }

        // Wait for child process to finish
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}