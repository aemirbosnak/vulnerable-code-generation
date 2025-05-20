//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define MAX_NUM_ARGS 10

void execute_command(char *cmd) {
    char *args[MAX_NUM_ARGS];
    char *token;
    int argc = 0;

    // Parse the command into arguments
    token = strtok(cmd, " \n");
    while (token != NULL && argc < MAX_NUM_ARGS - 1) {
        args[argc++] = token;
        token = strtok(NULL, " \n");
    }
    args[argc] = NULL;

    // Check if the command is to exit
    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    }

    // Create a new process
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // In child process
        execvp(args[0], args);
        // If execvp returns, an error occurred
        perror("Command execution failed");
        exit(1);
    } else {
        // In parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        }
    }
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Welcome to MyShell. Type 'exit' to quit.\n");

    while (1) {
        // Display prompt
        printf("myshell> ");
        fflush(stdout);

        // Read command from user
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            printf("\nError reading input\n");
            continue;
        }

        // Execute the command if it's not empty
        if (strlen(cmd) > 0) {
            execute_command(cmd);
        }
    }
    
    return 0;
}