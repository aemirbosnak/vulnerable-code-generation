//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

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

pid_t fork_and_exec(char **argv) {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    }

    return pid;
}

void handle_signal(int signum) {
    switch (signum) {
        case SIGINT:
            printf("\nInterrupted\n");
            break;
        case SIGQUIT:
            printf("\nQuit\n");
            break;
        case SIGTERM:
            printf("\nTerminated\n");
            break;
        default:
            printf("Unknown signal %d\n", signum);
    }
}

int main_loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        argv = split_command(input);
        if (argv[0] == NULL)
            continue;

        pid = fork_and_exec(argv);
        if (pid == -1) {
            perror("fork_and_exec");
        } else if (pid > 0) {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    main_loop();

    return 0;
}