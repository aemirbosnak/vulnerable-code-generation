//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0, buf_size = MAX_COMMAND_LENGTH;
    char **argv = malloc(sizeof(char *) * (argc + 1));
    argv[argc] = NULL;

    char *buf = malloc(buf_size);
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        if (argc == buf_size) {
            buf_size += MAX_COMMAND_LENGTH;
            argv = realloc(argv, sizeof(char *) * (argc + 1));
        }

        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Invalid command\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    argv = split_command(input);
    execute_command(argv);

    return 0;
}