//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split(char *str, char delim) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, delim);

    while(token!= NULL) {
        tokens[position] = token;
        position++;

        if(position == bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, delim);
    }

    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if(pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split(input, '\n');
        if(args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}