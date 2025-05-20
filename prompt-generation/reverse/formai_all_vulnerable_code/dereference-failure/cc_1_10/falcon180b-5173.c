//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIMITER " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    argv = malloc(MAX_ARGUMENTS * sizeof(char *));

    token = strtok(command, DELIMITER);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc == MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIMITER);
    }

    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();

    if (pid == -1) {
        perror("Fork failed");
        exit(1);
    }

    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        execute_command(argv);
    }

    return 0;
}