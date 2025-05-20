//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = strlen(str) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, str);
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(buf, DELIM);
    int count = 0;
    while(token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        fprintf(stderr, "Error: Command not found\n");
        return 1;
    }

    pid = fork();

    if(pid == -1) {
        fprintf(stderr, "Error: Fork failed\n");
        return 1;
    } else if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s not found\n", args[0]);
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Basic Unix-like Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);
        if(args[0] == NULL) {
            continue;
        }

        execute_command(args);
    }

    return 0;
}