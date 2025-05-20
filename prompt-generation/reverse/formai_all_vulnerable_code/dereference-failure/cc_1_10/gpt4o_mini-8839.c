//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 100
#define PROMPT "mysh> "

void execute_command(char *cmd) {
    char *args[MAX_ARGS];
    char *token = strtok(cmd, " \n");
    int i = 0;

    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL; // Null-terminate the argument list

    // Handle built-in commands
    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting the shell. Goodbye!\n");
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (i < 2) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd");
        }
        return;
    }

    // Fork a child process to execute the command
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("mysh");
        }
        exit(EXIT_FAILURE); // Exit child on failure
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child
        if (WIFEXITED(status)) {
            printf("Command executed with exit status: %d\n", WEXITSTATUS(status));
        }
    }
}

int main() {
    char cmd[MAX_CMD_LEN];

    printf("Welcome to my custom shell! Type 'exit' to leave.\n");

    while (1) {
        printf(PROMPT);
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            perror("fgets failed");
            continue; // Handle error but continue the loop
        }

        execute_command(cmd);
    }

    return 0; // This line will never be reached
}