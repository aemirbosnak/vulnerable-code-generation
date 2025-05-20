//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(line, DELIM);

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

pid_t fork() {
    pid_t pid;
    if((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if(tokens[0] == NULL)
        return 1;

    if(strcmp(tokens[0], "exit") == 0)
        return 0;

    pid = fork();

    if(pid == 0) {
        if(execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if(pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 1;
}

int main() {
    char input[MAX_LINE];
    char **tokens;

    while(1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        tokens = split_line(input);
        if(execute_command(tokens) == 0)
            break;

        free(tokens);
    }

    return 0;
}