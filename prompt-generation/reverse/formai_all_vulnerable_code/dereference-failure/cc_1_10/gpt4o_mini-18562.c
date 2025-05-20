//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100

void execute_command(char *cmd_line) {
    char *args[MAX_ARGS];
    char *token = strtok(cmd_line, " \n");
    int index = 0;

    while (token != NULL) {
        args[index++] = token;
        token = strtok(NULL, " \n");
    }
    args[index] = NULL; // Null-terminate the args array

    // Special case for "cd"
    if (strcmp(args[0], "cd") == 0) {
        if (index < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd failed");
        }
        return;
    }

    // Exit command
    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    // Forking a child process
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return;
    }
    
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE); // Exit if execvp returns
    } else {
        // Parent process
        wait(NULL); // Wait for child process to complete
    }
}

int main() {
    char cmd_line[MAX_CMD_LEN];

    while (1) {
        printf("myshell> "); // Display shell prompt
        if (fgets(cmd_line, sizeof(cmd_line), stdin) == NULL) {
            perror("Failed to read command");
            continue;
        }

        // If the command line is empty, continue
        if (strcmp(cmd_line, "\n") == 0) {
            continue; 
        }

        // Execute the command
        execute_command(cmd_line);
    }

    return 0;
}