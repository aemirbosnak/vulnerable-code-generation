//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1]!= NULL) {
            if (chdir(args[1])!= 0) {
                perror("chdir");
                return 1;
            }
        } else {
            fprintf(stderr, "Expected argument to \"cd\"\n");
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
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                return 1;
            }
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_LINE];
    char **args;

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);
        execute_command(args);

        free(args);
    }
}