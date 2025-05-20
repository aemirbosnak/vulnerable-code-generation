//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARG_LEN 256
#define DELIM " \t\r\n\a"

char **build_argv(char *command) {
    int argc = 0;
    char *argv[MAX_ARG_LEN];
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int main() {
    char input[MAX_COMMAND_LEN];
    char **argv;
    pid_t pid;
    int status;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LEN, stdin);

    argv = build_argv(input);

    if (argv[0] == NULL) {
        printf("Invalid command\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        execvp(argv[0], argv);
        printf("Exec failed\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}