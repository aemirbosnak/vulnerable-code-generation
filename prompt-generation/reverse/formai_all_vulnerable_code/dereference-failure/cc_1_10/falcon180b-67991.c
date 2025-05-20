//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Basic Unix-like Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        pid_t child_pid = fork();
        if (child_pid == 0) {
            execute_command(args);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(MAX_ARGUMENTS * sizeof(char*));
    int argc = 0;
    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user.\n");
    }
}