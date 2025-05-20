//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;
    char *saveptr = NULL;

    while (line[bufsize]) {
        if (bufsize >= MAX_LINE) {
            fprintf(stderr, "Line too long.\n");
            exit(1);
        }

        token = strtok_r(line + bufsize, DELIM, &saveptr);
        if (token == NULL)
            break;

        tokens = realloc(tokens, sizeof(char *) * ++words);
        tokens[words - 1] = token;

        bufsize += strlen(token) + 1;
    }

    tokens[words] = NULL;
    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return;

    switch (fork()) {
        case -1:
            fprintf(stderr, "Fork failed: %s\n", strerror(errno));
            exit(1);

        case 0:
            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "Execute failed: %s\n", strerror(errno));
                exit(1);
            }

            exit(0);

        default:
            waitpid(pid, &status, 0);
            break;
    }
}

int main() {
    char input[MAX_LINE];
    char **args;

    printf("Surrealist Shell\n");

    while (fgets(input, MAX_LINE, stdin)) {
        args = split_line(input);
        execute_command(args);
    }

    return 0;
}