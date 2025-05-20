//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(sizeof(char *) * 64);

    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        argv[argc++] = token;
        if (argc >= 64) {
            argv = realloc(argv, sizeof(char *) * (argc + 64));
        }
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (strcmp(argv[0], "exit") == 0) {
        return 1;
    } else if (strcmp(argv[0], "cd") == 0) {
        if (chdir(argv[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();
        if (pid == -1) {
            perror("fork");
            return 1;
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
                return 1;
            }
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    argv = split_command(input);
    execute_command(argv);

    free(argv);
}

int main(void) {
    loop();

    return 0;
}