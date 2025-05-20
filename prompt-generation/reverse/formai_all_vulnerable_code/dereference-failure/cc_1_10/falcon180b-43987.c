//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t launch_process(char **arguments);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input);
        if (arguments == NULL) {
            continue;
        }

        pid = launch_process(arguments);
        if (pid == -1) {
            printf("Error: Failed to launch process.\n");
        } else {
            waitpid(pid, NULL, 0);
        }

        free(arguments);
    }

    return 0;
}

char **split_command(char *command) {
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        arguments[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    arguments[argc] = NULL;

    return arguments;
}

pid_t launch_process(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork process.\n");
        return -1;
    } else if (pid == 0) {
        execvp(arguments[0], arguments);
        printf("Error: Failed to execute process.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

void handle_signal(int signum) {
    printf("\nInterrupted by signal %d.\n", signum);
}