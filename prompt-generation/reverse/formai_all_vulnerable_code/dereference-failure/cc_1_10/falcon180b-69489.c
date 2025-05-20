//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t fork();
int execute_command(char **args);
void signal_handler(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Enter commands. Type 'exit' to quit.\n");

    while (1) {
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed: %s\n", strerror(errno));
            continue;
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *str) {
    char *token;
    int count = 0;
    char **args = malloc(sizeof(char *) * MAX_ARGUMENTS);

    token = strtok(str, DELIM);
    while (token!= NULL) {
        args[count++] = token;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    args[count] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed: %s\n", strerror(errno));
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Execvp failed: %s\n", strerror(errno));
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void signal_handler(int signum) {
    fprintf(stderr, "Signal %d received\n", signum);
}