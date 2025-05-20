//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_SIZE 1024
#define DELIM " \t\n\r\f\v"

char **split_line(char *line)
{
    int count = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while ((token = strtok(line, DELIM))) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[i] = token;
        i++;
        line = NULL;
    }

    tokens[count - 1] = NULL;
    return tokens;
}

int launch_shell(char **args)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}

int main()
{
    char input[MAX_LINE_SIZE];
    char **args;
    int bg = 0, exit_shell = 0;

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_LINE_SIZE, stdin);

        args = split_line(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(args[0], "bg") == 0) {
            bg = 1;
        } else {
            launch_shell(args);
        }

        if (bg) {
            bg = 0;
        }
    }

    return 0;
}