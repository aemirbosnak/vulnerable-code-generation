//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: single-threaded
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
    char *token;

    argv = malloc((MAX_COMMAND_LENGTH / 2) * sizeof(char *));
    if (argv == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            fprintf(stderr, "Error: Command too long.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();
    if (pid == -1) {
        fprintf(stderr, "Error: fork failed.\n");
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
            fprintf(stderr, "Error: %s not found.\n", argv[0]);
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: fork failed.\n");
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

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        if (argv[0] == NULL) {
            continue;
        }

        execute_command(argv);
    }

    return 0;
}