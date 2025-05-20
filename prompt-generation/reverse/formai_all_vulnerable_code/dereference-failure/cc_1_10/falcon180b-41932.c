//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **arguments);
void handle_signal(int signal);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input);
        pid = fork();

        if (pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        arguments[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            printf("Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signal) {
    printf("Interrupted by signal %d.\n", signal);
    exit(1);
}