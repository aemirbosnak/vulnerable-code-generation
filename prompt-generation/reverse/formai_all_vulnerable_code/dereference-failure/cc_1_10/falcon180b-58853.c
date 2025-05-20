//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t launch_process(char **args);
void execute_command(char **args);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_command(input);
        if (args[0] == NULL) {
            continue;
        }

        pid = launch_process(args);
        if (pid == -1) {
            printf("Error: Failed to launch process.\n");
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(1024 * sizeof(char*));
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t launch_process(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        return -1;
    } else if (pid == 0) {
        execute_command(args);
        exit(0);
    } else {
        waitpid(pid, &status, 0);
        return pid;
    }
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;
    }

    pid = fork();
    if (pid == -1) {
        printf("Error: Failed to fork.\n");
        return;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error: Failed to execute command.\n");
        }
        exit(0);
    } else {
        waitpid(pid, &status, 0);
    }
}