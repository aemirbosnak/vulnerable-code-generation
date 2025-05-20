//Falcon-180B DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

char **build_argv(char *command) {
    int argc = 0;
    char *token = strtok(command, DELIM);
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));

    while (token!= NULL) {
        argv[argc] = token;
        argc++;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;
    int status;

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        argv = build_argv(input_buffer);

        pid = fork();
        if (pid == 0) {
            execvp(argv[0], argv);
            fprintf(stderr, "Command not found.\n");
            exit(1);
        } else if (pid < 0) {
            fprintf(stderr, "Fork failed.\n");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}