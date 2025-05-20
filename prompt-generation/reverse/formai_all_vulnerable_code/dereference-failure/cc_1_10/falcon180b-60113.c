//Falcon-180B DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Execvp failed\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_input(char *input) {
    char *token;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int num_args = 0;

    token = strtok(input, " ");
    while (token!= NULL) {
        args[num_args] = token;
        num_args++;
        if (num_args >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    execute_command(args);
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        handle_input(input);
    }

    return 0;
}