//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENT_LENGTH 256
#define DELIM " \t\n\r\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == 0) {
        return pid;
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    } else if (strcmp(argv[0], "cd") == 0) {
        if (chdir(argv[1])!= 0) {
            perror("chdir");
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void loop(char **environment) {
    char input[MAX_COMMAND_LENGTH];
    char **command_argv;
    pid_t pid;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    command_argv = split_command(input);
    pid = fork();

    if (pid == 0) {
        execute_command(command_argv);
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
}

int main(int argc, char **argv, char **environment) {
    loop(environment);
    return 0;
}