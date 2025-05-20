//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGS 10

void print_prompt() {
    printf(">>");
    fflush(stdout);
}

char **parse_command(char *command_str) {
    char **args = malloc(sizeof(char*) * MAX_NUM_ARGS);
    char *token;
    int num_args = 0;

    token = strtok(command_str, " \t\n\r");

    while(token != NULL && num_args < MAX_NUM_ARGS) {
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " \t\n\r");
    }

    args[num_args] = NULL;

    return args;
}

void execute_command(char **args) {
    pid_t pid, wait_pid;
    int status;

    pid = fork();

    if(pid == -1) {
        printf("Error: fork failed\n");
        return;
    }
    else if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            printf("Error: couldn't execute command\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        do {
            wait_pid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

int main() {
    char command_string[MAX_COMMAND_LENGTH];

    while(1) {
        print_prompt();

        if(fgets(command_string, MAX_COMMAND_LENGTH, stdin) == NULL) {
            continue;
        }

        char **args = parse_command(command_string);

        if(args[0] == NULL) {
            continue;
        }

        if(strcmp(args[0], "exit") == 0) {
            printf("Exiting...\n");
            return 0;
        }

        execute_command(args);

        free(args);
    }

    return 0;
}