//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
        case SIGTERM:
            printf("\nExiting...\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Received signal %d\n", signum);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv = NULL;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        pid = launch_shell(argv);

        if (pid == -1) {
            printf("Error launching shell\n");
        } else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}