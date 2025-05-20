//Falcon-180B DATASET v1.0 Category: System administration ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

pid_t launch_shell(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Exec failed.\n");
            exit(1);
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }

    return pid;
}

void handle_signal(int signum) {
    fprintf(stdout, "Received signal %d.\n", signum);
    exit(0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [argument...]\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    char *command = argv[1];
    char **arguments = split_command(command);
    pid_t shell_pid = launch_shell(arguments);

    waitpid(shell_pid, NULL, 0);

    return 0;
}