//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **command_argv = NULL;

    printf("Enter commands. Type 'exit' to quit.\n");

    while (1) {
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        command_argv = split_command(input);
        if (command_argv == NULL) {
            printf("Error: Out of memory.\n");
        } else {
            execute_command(command_argv);
            free(command_argv);
        }
    }

    return 0;
}