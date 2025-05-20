//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024

char **split_line(char *line);
int execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

char **split_line(char *line) {
    int argc = 0, i = 0;
    char **argv = malloc(MAX_ARGS * sizeof(char*));
    char *token;

    while ((token = strtok(line, " "))!= NULL) {
        argv[argc++] = token;
        i++;

        if (argc >= MAX_ARGS - 1) {
            fprintf(stderr, "Too many arguments.\n");
            exit(1);
        }
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

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
        waitpid(pid, &status, WUNTRACED);
    }

    return 0;
}

void loop(void) {
    char input[MAX_LINE];
    char **args;

    printf("> ");
    fgets(input, MAX_LINE, stdin);

    args = split_line(input);
    execute_command(args);

    free(args);
}