//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
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
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: Empty command.\n");
        return -1;
    }

    pid = fork();
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
            fprintf(stdout, "\nExiting...\n");
            exit(EXIT_SUCCESS);
        default:
            fprintf(stdout, "Received signal %d\n", signum);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;
    int status;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    fprintf(stdout, "Enter commands followed by ENTER. Type 'exit' to quit.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        argv = split_command(input);
        pid = launch_shell(argv);

        if (pid == -1) {
            continue;
        }

        waitpid(pid, &status, 0);
    }

    return 0;
}