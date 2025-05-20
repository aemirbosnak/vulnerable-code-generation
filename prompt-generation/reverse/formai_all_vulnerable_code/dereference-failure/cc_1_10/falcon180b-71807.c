//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **argv = malloc(MAX_COMMAND_ARGUMENTS * sizeof(char *));
    char *token = strtok(line, DELIM);

    while (token!= NULL && argc < MAX_COMMAND_ARGUMENTS) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop(void) {
    char input[MAX_LINE_SIZE];
    char **args;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_SIZE, stdin);

        args = split_line(input);
        execute_command(args);

        free(args);
    }
}