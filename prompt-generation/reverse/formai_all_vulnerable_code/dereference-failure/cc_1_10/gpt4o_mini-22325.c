//GPT-4o-mini DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARG_LENGTH 100
#define MAX_NUM_ARGS 20

void execute_command(char *cmd) {
    char *args[MAX_NUM_ARGS];
    char *token = strtok(cmd, " \n");
    int i = 0;
    
    while (token != NULL && i < MAX_NUM_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    // Handle redirection
    for (int j = 0; j < i; j++) {
        if (strcmp(args[j], ">") == 0) {
            // Output redirection
            args[j] = NULL; // Cut the list at this point
            int fd = open(args[j + 1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
            dup2(fd, STDOUT_FILENO);
            close(fd);
            break;
        }
        else if (strcmp(args[j], "<") == 0) {
            // Input redirection
            args[j] = NULL; // Cut the list at this point
            int fd = open(args[j + 1], O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
            break;
        }
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        perror("Fork failed");
    }
}

void run_shell() {
    char cmd[MAX_CMD_LENGTH];

    while (1) {
        printf("brave-shell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break; // Exit on EOF
        }

        // If there's a pipe
        char *pipe_cmd = strtok(cmd, "|");
        while (pipe_cmd != NULL) {
            execute_command(pipe_cmd);
            pipe_cmd = strtok(NULL, "|");
        }
    }
}

int main() {
    printf("Welcome to Brave Shell! Type 'exit' to quit.\n");
    run_shell();
    return 0;
}