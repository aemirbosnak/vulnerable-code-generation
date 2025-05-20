//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *input);
pid_t fork_process(char **args);
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);

    printf("Welcome to the Excited Shell!\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        if (args[0] == NULL)
            continue;

        pid = fork_process(args);
        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

char **split_string(char *input) {
    int count = 0;
    char **tokens = malloc(1024 * sizeof(char *));
    char *token = strtok(input, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork_process(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }

    waitpid(pid, &status, 0);
    return status;
}

void handle_signal(int signum) {
    if (signum == SIGINT) {
        printf("\nInterrupted by user. Exiting...\n");
        exit(0);
    }
}