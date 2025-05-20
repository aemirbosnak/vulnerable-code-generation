//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024
#define MAX_ARGS 64

int main() {
    char input[MAX_LENGTH];
    char *args[MAX_ARGS];
    int status = 0;

    while (1) {
        printf("shell > ");
        fgets(input, MAX_LENGTH, stdin);

        if (strlen(input) == 1) continue;

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        char *token = strtok(input, " ");
        int i = 0;

        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
        } else if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}