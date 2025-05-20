//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
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
        exit(1);
    } else if (pid == 0) {
        execvp(argv[0], argv);
        perror("execvp");
        exit(1);
    }

    return pid;
}

void handle_signal(int signum) {
    pid_t pid;
    int status;

    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        if (WIFEXITED(status)) {
            printf("[%d] %d\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("[%d] terminated by signal %d\n", pid, WTERMSIG(status));
        }
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv = NULL;
    pid_t pid;

    printf("Ken Thompson's Unix shell\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        argv = split_command(input);

        if (argv[0] == NULL) {
            continue;
        }

        pid = launch_shell(argv);

        if (pid > 0) {
            printf("[%d]\n", pid);
        }
    }

    return 0;
}