//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS_LENGTH 100
#define MAX_NUM_ARGS 10

void execute_command(char *command, char **args) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // child process
        if (execvp(command, args) == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else { // parent process
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("Command returned non-zero exit status.\n");
        }
    }
}

void read_command(char **command, char ***args, int *num_args) {
    char *input = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char *token = strtok(input, " \n");
    *command = strdup(token);

    *args = (char **) malloc(MAX_NUM_ARGS * sizeof(char *));
    *num_args = 0;
    while (token != NULL && *num_args < MAX_NUM_ARGS) {
        (*args)[*num_args] = strdup(token);
        (*num_args)++;
        token = strtok(NULL, " \n");
    }
    (*args)[*num_args] = NULL; // must be NULL-terminated

    free(input);
}

int main() {
    char *command;
    char **args;
    int num_args;

    while (1) {
        printf("> ");
        read_command(&command, &args, &num_args);

        if (strcmp(command, "exit") == 0) {
            break;
        } else {
            execute_command(command, args);
        }
    }

    free(command);
    for (int i = 0; i < num_args; i++) {
        free(args[i]);
    }
    free(args);

    return 0;
}