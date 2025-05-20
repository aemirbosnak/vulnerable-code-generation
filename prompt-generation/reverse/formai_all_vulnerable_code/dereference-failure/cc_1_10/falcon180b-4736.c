//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if(str == NULL) {
        fprintf(stderr, "split_string: string is NULL\n");
        exit(1);
    }

    token = strtok(str, DELIM);
    while(token!= NULL) {
        if(position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }
        tokens[position++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;

    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;

    if(args[0] == NULL) {
        fprintf(stderr, "launch_shell: command not found\n");
        return -1;
    }

    pid = fork();

    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            fprintf(stderr, "launch_shell: %s\n", strerror(errno));
            exit(1);
        }
        exit(0);
    } else if(pid < 0) {
        fprintf(stderr, "launch_shell: fork failed\n");
        exit(1);
    }

    return pid;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    pid_t pid;

    if(argc < 2) {
        fprintf(stderr, "Usage: %s [command]\n", argv[0]);
        exit(1);
    }

    printf("Welcome to the %s shell!\n", argv[0]);

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        pid = launch_shell(args);

        if(pid == -1) {
            continue;
        } else {
            waitpid(pid, NULL, WUNTRACED);
        }
    }

    return 0;
}