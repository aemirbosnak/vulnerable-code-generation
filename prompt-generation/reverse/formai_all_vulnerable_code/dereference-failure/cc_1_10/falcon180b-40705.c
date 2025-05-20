//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

// Function prototypes
char **split_command(char *command);
pid_t execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *current_dir = getcwd(NULL, 0);
    printf("Current directory: %s\n", current_dir);
    free(current_dir);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_command(input);
        pid_t pid = execute_command(args);
        waitpid(pid, NULL, 0);
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    return args;
}

pid_t execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return pid;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        exit(0);
    }
}