//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    printf("Welcome to the Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        arguments = split_command(input);
        if (arguments == NULL) {
            continue;
        }

        pid = fork();
        if (pid == -1) {
            printf("Error forking process.\n");
            exit(1);
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            execute_command(arguments);
            exit(0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token;
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok(command, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t fork() {
    return fork();
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        printf("Error forking process.\n");
        exit(1);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error executing command.\n");
            exit(1);
        }
    }

    return 0;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted by user.\n");
            exit(0);
        default:
            printf("Received unknown signal.\n");
            exit(1);
    }
}