//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_command(input);
        pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            printf("Fork failed\n");
        } else {
            wait(NULL);
        }

        free(args);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, DELIM);

    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;

        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Command not found\n");
            exit(1);
        }
    } else if (pid < 0) {
        printf("Fork failed\n");
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}