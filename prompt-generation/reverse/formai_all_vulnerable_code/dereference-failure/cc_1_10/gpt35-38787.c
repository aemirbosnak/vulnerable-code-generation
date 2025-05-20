//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_LENGTH 80
#define MAX_ARGS 10

int main() {
    char *input;
    char *args[MAX_ARGS];
    int status;
    bool foreground = true;

    while (true) {
        printf("retro-shell > ");
        fflush(stdout);

        // Read input from user
        input = malloc(MAX_LENGTH * sizeof(char));
        fgets(input, MAX_LENGTH, stdin);

        // Remove newline character and replace with null terminator
        input[strlen(input)-1] = '\0';

        // Split input into separate arguments
        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        // Handle special commands
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        if (strcmp(args[0], "cd") == 0) {
            chdir(args[1]);
            continue;
        }

        if (strcmp(args[i-1], "&") == 0) {
            foreground = false;
            args[i-1] = NULL;
        }

        // Create child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error");
            exit(1);
        }

        if (pid == 0) {
            // Child process

            if (execvp(args[0], args) < 0) {
                perror("Error");
                exit(1);
            }
        }
        else {
            // Parent process 
            
           if (foreground) {
                waitpid(pid, &status, 0);
            }
        }
    }
    return 0;
}