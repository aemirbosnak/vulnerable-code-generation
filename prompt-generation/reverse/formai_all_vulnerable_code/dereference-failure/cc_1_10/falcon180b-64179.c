//Falcon-180B DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    int i = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc] = token;
        argc++;
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
        fprintf(stderr, "Error forking process: %s\n", strerror(errno));
        return -1;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Error executing command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
        return pid;
    }
}

void handle_input(char *input) {
    char **argv = split_command(input);
    pid_t pid = launch_shell(argv);

    if (pid!= -1) {
        waitpid(pid, NULL, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Enter commands to execute:\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        handle_input(input);
        memset(input, 0, MAX_COMMAND_LENGTH);
    }

    return 0;
}