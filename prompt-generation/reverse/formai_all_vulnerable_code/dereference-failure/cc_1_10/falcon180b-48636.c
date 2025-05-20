//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork_and_exec(char **args);
void handle_signal(int signum);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input_buffer);
        if (args == NULL) {
            continue;
        }

        pid = fork_and_exec(args);

        if (pid == -1) {
            fprintf(stderr, "Error forking process.\n");
        } else if (pid > 0) {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int argc = 0;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);

        if (argc >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
    }

    args[argc] = NULL;

    return args;
}

pid_t fork_and_exec(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error executing command.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return pid;
    }
}

void handle_signal(int signum) {
    fprintf(stderr, "Interrupted by signal %d\n", signum);
}