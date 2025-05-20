//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
/* This is a simple Unix-like shell in C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Unix-like shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if(args[0] == NULL)
            continue;

        execute_command(args);
    }

    return 0;
}

char **split_string(char *string) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(string, DELIM);

    while(token!= NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL)
        return 1;

    if(strcmp(args[0], "exit") == 0) {
        return 0;
    } else if(strcmp(args[0], "cd") == 0) {
        if(args[1]!= NULL) {
            if(chdir(args[1])!= 0) {
                perror("chdir");
            }
        } else {
            printf("Usage: cd [directory]\n");
        }
    } else if(strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
    } else {
        pid = fork();

        if(pid == -1) {
            perror("fork");
        } else if(pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 1;
}