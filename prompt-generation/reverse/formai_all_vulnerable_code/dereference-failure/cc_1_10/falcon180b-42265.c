//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define MAX_ARGUMENTS 100

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(sizeof(char *) * MAX_ARGUMENTS);
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
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

void shell_loop(void) {
    while (1) {
        printf("> ");
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char *command = strtok(input, "\n");
        char **argv = split_command(command);
        int result = execute_command(argv);
        if (result!= 0) {
            printf("Command failed with exit code %d.\n", result);
        }
    }
}

int main() {
    shell_loop();
    return 0;
}