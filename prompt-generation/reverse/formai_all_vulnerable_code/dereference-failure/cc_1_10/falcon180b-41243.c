//Falcon-180B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

char **build_argv(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token;
    char *saveptr = NULL;

    token = strtok_r(command, " ", &saveptr);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments.\n");
            exit(1);
        }
        token = strtok_r(NULL, " ", &saveptr);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "Error: Failed to execute command.\n");
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Error: Failed to fork.\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Error: Command terminated abnormally.\n");
            exit(1);
        }
    }
}

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **argv;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        argv = build_argv(input_buffer);
        status = execute_command(argv);

        if (status == 0) {
            printf("Command executed successfully.\n");
        } else {
            printf("Command failed with status %d.\n", status);
        }
    }

    return 0;
}