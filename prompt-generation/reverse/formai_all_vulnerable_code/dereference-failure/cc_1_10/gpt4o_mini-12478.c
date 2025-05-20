//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 100

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    int background = 0;

    // Tokenize the command
    char *token = strtok(cmd, " \n");
    int i = 0;
    
    while (token != NULL) {
        // Check for background execution
        if (strcmp(token, "&") == 0) {
            background = 1;
            break;
        }
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; // NULL-terminate the array

    // Fork a new process to execute the command
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) { // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE); // Exit if exec fails
    } else { // Parent process
        if (!background) {
            waitpid(pid, NULL, 0); // Wait for the child to complete
        } else {
            printf("Started process %d in background\n", pid);
        }
    }
}

void shell_loop() {
    char *cmd = NULL;
    size_t len = 0;
    printf("Simple Shell > ");

    while (getline(&cmd, &len, stdin) != -1) {
        // Ignore empty commands
        if (strlen(cmd) > 1) {
            execute_command(cmd);
        }
        printf("Simple Shell > ");
    }

    free(cmd);
}

int main() {
    printf("Welcome to Simple Shell! Type 'exit' to quit.\n");
    shell_loop();
    return 0;
}