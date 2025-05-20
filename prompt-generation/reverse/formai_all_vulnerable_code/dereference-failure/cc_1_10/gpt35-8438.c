//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_CMD_LENGTH 100

void execute_command(char *cmd, char **args);
void parse_command(char *line, char **args);

int main() {
    char *line = NULL;
    char *args[MAX_ARGS];
    size_t len = 0;
    ssize_t read;

    while (1) {
        printf(">> ");
        read = getline(&line, &len, stdin);

        if (read == -1) {
            perror("Error reading line");
            continue;
        }

        if (strcmp(line, "exit\n") == 0 || strcmp(line, "quit\n") == 0) {
            printf("Exiting...\n");
            break;
        }

        parse_command(line, args);
        if (args[0] != NULL) {
            execute_command(args[0], args);
        }

        // Free memory
        for (int i = 0; i < MAX_ARGS; i++) {
            free(args[i]);
        }
    }

    // Free memory
    free(line);

    return 0;
}

void parse_command(char *line, char **args) {
    int i = 0;
    char *token;

    token = strtok(line, " \n");
    while (token != NULL) {
        args[i] = malloc(sizeof(char) * MAX_CMD_LENGTH);
        strcpy(args[i], token);
        token = strtok(NULL, " \n");
        i++;
    }
    args[i] = NULL;
}

void execute_command(char *cmd, char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        execvp(cmd, args);
        // If execvp returns, there has been an error
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking process");
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}