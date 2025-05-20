//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 1024
#define MAX_LINE_LENGTH 4096

char **split_line(char *line);
void execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char **args;
    pid_t child_pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);

        args = split_line(input_buffer);
        if (args[0] == NULL) {
            continue;
        }

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(1);
        } else if (child_pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_line(char *line) {
    int buf_size = MAX_LINE_LENGTH;
    int args_count = 0;
    char **args = malloc(sizeof(char *));

    char *token = strtok(line, " ");
    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++args_count);
        args[args_count - 1] = strdup(token);
        token = strtok(NULL, " ");
    }

    args[args_count] = NULL;
    return args;
}

void execute_command(char **args) {
    pid_t child_pid;

    if (args[0] == NULL) {
        return;
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    } else if (child_pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(child_pid, NULL, 0);
    }
}

void handle_signal(int signum) {
    printf("\nSignal %d received\n", signum);
    exit(0);
}