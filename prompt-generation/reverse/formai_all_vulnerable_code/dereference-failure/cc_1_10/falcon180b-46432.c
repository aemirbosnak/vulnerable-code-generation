//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        pid_t pid = fork();

        if (pid == 0) {
            execute_command(args);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (strlen(command) / MAX_COMMAND_LENGTH + 1));
    char *token = strtok(command, DELIM);
    int i = 0;
    while (token!= NULL) {
        args[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(args[i], token);
        i++;
        token = strtok(NULL, DELIM);
    }
    args[i] = NULL;
    return args;
}

pid_t fork(void) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
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
            printf("\nUnknown signal %d received.\n", signum);
    }
}