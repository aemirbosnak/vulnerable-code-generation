//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **split_string(char *str);
pid_t execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        pid = execute_command(args);

        waitpid(pid, NULL, 0);
    }

    return 0;
}

char **split_string(char *str) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(str, DELIM);
    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

pid_t execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Execute command");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Fork");
        exit(1);
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return pid;
}

void handle_signal(int signum) {
    if (signum == SIGINT || signum == SIGQUIT || signum == SIGTERM) {
        printf("\nExiting...\n");
        exit(0);
    }
}