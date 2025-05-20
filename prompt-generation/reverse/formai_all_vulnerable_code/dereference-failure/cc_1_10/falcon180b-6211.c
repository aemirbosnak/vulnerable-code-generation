//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **split_string(char *input) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(input, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int launch_shell(char **argv) {
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

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv = NULL;
    int background = 0;
    int exit_shell = 0;

    printf("Welcome to the Shell!\n");

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_string(input);

        if (argv[0] == NULL) {
            continue;
        }

        if (strcmp(argv[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(argv[0], "bg") == 0 && argv[1]!= NULL) {
            printf("Putting %s in background...\n", argv[1]);
            launch_shell(argv);
            background = 1;
        } else if (strcmp(argv[0], "jobs") == 0) {
            if (background) {
                system("jobs");
            }
        } else {
            launch_shell(argv);
        }
    }

    return 0;
}