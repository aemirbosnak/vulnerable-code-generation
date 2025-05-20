//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t launch_shell(char **args);
void execute_command(char **args);
void handle_signal(int signum);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Welcome to the Basic Unix-like Shell!\n");
    printf("Enter commands followed by enter.\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = launch_shell(args);
        waitpid(pid, NULL, 0);
    }

    return 0;
}

char **split_string(char *str) {
    int argc = 0;
    char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execute_command(args);
        exit(EXIT_SUCCESS);
    }

    return pid;
}

void execute_command(char **args) {
    int status;
    pid_t pid;

    if (args[0] == NULL) {
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }

    waitpid(pid, &status, 0);
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user.\n");
    }
}