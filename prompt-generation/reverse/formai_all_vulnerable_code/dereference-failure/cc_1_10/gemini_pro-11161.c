//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 characters per line, per POSIX */

char** parse_args(char* line)
{
    char** args = malloc(sizeof(char*) * MAX_LINE);
    char* arg = strtok(line, " ");
    int i = 0;
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args;
}

int main()
{
    char line[MAX_LINE];
    char** args;
    int status;

    while (1) {
        printf("> ");
        fgets(line, MAX_LINE, stdin);
        if (strcmp(line, "exit\n") == 0) {
            exit(0);
        }
        args = parse_args(line);
        if (args[0] == NULL) {
            continue;
        }
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            wait(&status);
        }
        free(args);
    }

    return 0;
}