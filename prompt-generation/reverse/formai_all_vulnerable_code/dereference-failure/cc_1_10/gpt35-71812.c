//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_SIZE 512

int main() {
    char input[MAX_SIZE];
    char *args[MAX_ARGS];
    pid_t pid;
    int status;

    printf("Welcome to my Unix-like shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_SIZE, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Tokenize input string into an array of arguments
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL && i < MAX_ARGS - 1) {
            i++;
            args[i] = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Check if user wants to exit
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Fork a new process and execute the command
        pid = fork();
        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            printf("Unknown command: %s\n", args[0]);
            exit(0);
        } else if (pid > 0) {
            // Parent process
            waitpid(pid, &status, 0);
        } else {
            // Error forking process
            printf("Error forking process\n");
        }
    }

    return 0;
}