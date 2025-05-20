//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;
    char *saveptr = NULL;

    token = strtok_r(command, " ", &saveptr);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char*) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok_r(NULL, " ", &saveptr);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signum) {
    char **argv;
    int argc;

    switch (signum) {
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
            printf("\nExiting...\n");
            exit(0);
        default:
            argv = split_command("ps aux");
            argc = 0;
            execute_command(argv);
            break;
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fflush(stdout);

        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **argv = split_command(input);
        int argc = 0;

        execute_command(argv);

        for (int i = 0; argv[i]!= NULL; i++) {
            free(argv[i]);
        }
        free(argv);
    }

    return 0;
}