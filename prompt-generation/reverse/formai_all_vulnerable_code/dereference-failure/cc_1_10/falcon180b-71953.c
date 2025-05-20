//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, " ");
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char*) * ++argc);
        argv[argc-1] = strdup(token);
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    return argv;
}

int main(int argc, char *argv[]) {
    char input[MAX_LINE];
    char **args;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        args = split_line(input);

        if (args[0] == NULL || strcmp(args[0], "exit") == 0) {
            break;
        } else {
            pid = fork();

            if (pid == 0) {
                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}