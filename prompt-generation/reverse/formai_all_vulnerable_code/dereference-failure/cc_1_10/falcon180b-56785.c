//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = malloc(sizeof(char *));

    while ((command[i] = strsep(&command, DELIM))!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(command[i]);
    }

    return argv;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **argv) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_sigint(int signum) {
    printf("\nInterrupted\n");
    exit(1);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv = NULL;

    signal(SIGINT, handle_sigint);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        execute_command(argv);

        free(argv);
    }

    return 0;
}