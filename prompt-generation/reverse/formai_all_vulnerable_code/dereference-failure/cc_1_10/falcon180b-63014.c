//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
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
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char *command = strtok(input, DELIM);
        char **args = split_command(command);
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (strlen(command) / 4 + 1));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        args[argc] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(args[argc], token);
        argc++;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;
    return args;
}

pid_t fork(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }
    return 0;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted by user.\n");
            break;
        case SIGTERM:
            printf("\nTerminated.\n");
            break;
        default:
            printf("\nUnknown signal %d.\n", signum);
            break;
    }
    exit(0);
}