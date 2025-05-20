//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define MAX_ARG_NUM 10
#define DELIM " \t\r\n\a"

char **split_command(char *command, int *argc) {
    char **args = malloc(MAX_ARG_NUM * sizeof(char*));
    int i = 0;
    char *token = strtok(command, DELIM);
    while (token!= NULL && i < MAX_ARG_NUM) {
        args[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }
    args[i] = NULL;
    *argc = i;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LEN];
    char **args;
    int arg_count;
    int status;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LEN, stdin);

        args = split_command(input, &arg_count);
        status = execute_command(args);

        free(args);
    }

    return 0;
}