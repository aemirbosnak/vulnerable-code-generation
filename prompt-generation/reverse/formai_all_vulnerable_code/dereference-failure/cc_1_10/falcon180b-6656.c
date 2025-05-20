//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        print_prompt();
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **args = split_command(input);
        pid_t pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            printf("Error forking\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token = strtok(command, " ");

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;
    return args;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command\n");
            return 1;
        }
    } else if (pid < 0) {
        printf("Error forking\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}