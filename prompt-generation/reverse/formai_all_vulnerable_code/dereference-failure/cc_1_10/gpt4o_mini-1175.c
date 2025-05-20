//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARG_LENGTH 100
#define MAX_NUM_ARGS 10

void print_prompt() {
    printf("$ ");
}

char **parse_command(char *cmd) {
    char **args = malloc(MAX_NUM_ARGS * sizeof(char *));
    char *arg = strtok(cmd, " \n");
    int i = 0;

    while (arg != NULL && i < MAX_NUM_ARGS - 1) {
        args[i++] = arg;
        arg = strtok(NULL, " \n");
    }
    args[i] = NULL;  // NULL terminate the array of arguments
    return args;
}

void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WNOHANG);
        } while (wpid == 0);  // Wait for the child process to finish
    }
}

void free_arguments(char **args) {
    free(args);
}

int main() {
    char cmd[MAX_CMD_LENGTH];

    while (1) {
        print_prompt();  // Print shell prompt

        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            if (feof(stdin)) {
                printf("\nExiting shell...\n");
                break;  // Exit on Ctrl+D
            }
            perror("Read failed");
            continue;
        }

        if (strcmp(cmd, "exit\n") == 0) {
            printf("Exiting shell...\n");
            break;  // Exit on "exit" command
        }

        char **args = parse_command(cmd);  // Parse command
        if (args[0] != NULL) {  // Check if command is not empty
            execute_command(args);  // Execute command
        }
        free_arguments(args);  // Free allocated memory
    }

    return 0;
}