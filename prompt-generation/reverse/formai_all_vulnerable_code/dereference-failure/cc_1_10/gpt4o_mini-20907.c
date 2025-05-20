//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define MAX_ARGS 10

void execute_command(char *input) {
    char *args[MAX_ARGS];
    char *token;
    int i = 0;

    token = strtok(input, " \n");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; // last argument should be NULL for execvp

    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting shell. Bye!\n");
        exit(0);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(0); // Exit the child process
    } else {
        // Parent process
        wait(NULL); // Wait for child to terminate
    }
}

void display_prompt() {
    printf("custom-shell> ");
}

int main() {
    char input[MAX_CMD_LEN];

    while (1) {
        display_prompt();
        if (fgets(input, sizeof(input), stdin) == NULL) {
            if (feof(stdin)) {
                printf("\n"); // Handle EOF gracefully
                break;
            }
            continue; // Handle error in input
        }
        
        // Execute the command
        execute_command(input);
    }

    return 0;
}