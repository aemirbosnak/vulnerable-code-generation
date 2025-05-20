//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARG_LENGTH 64
#define MAX_ARGS 16

char *read_command() {
    char *command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    printf(">>> ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    size_t len = strlen(command);
    if (command[len-1] == '\n') {
        command[len-1] = '\0';
    }
    return command;
}

char **parse_command(char *command) {
    char **args = malloc((MAX_ARGS+1) * sizeof(char *));
    char *arg = strtok(command, " ");
    int i = 0;
    while (arg != NULL && i < MAX_ARGS) {
        args[i] = arg;
        arg = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;
    return args;
}

void execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command not found.\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        printf("Error forking process.\n");
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char **argv) {
    char *command;
    char **args;

    do {
        command = read_command();
        args = parse_command(command);
        execute_command(args);
        free(command);
        free(args);
    } while(1);

    return EXIT_SUCCESS;
}