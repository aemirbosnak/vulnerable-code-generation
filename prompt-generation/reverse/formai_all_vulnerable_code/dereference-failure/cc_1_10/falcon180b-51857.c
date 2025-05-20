//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position == bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1]!= NULL) {
            if (chdir(tokens[1])!= 0) {
                fprintf(stderr, "Error: No such directory - %s\n", tokens[1]);
            }
        } else {
            fprintf(stderr, "Error: Directory not specified\n");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error: Fork Failed\n");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                fprintf(stderr, "Error: Command not found - %s\n", tokens[0]);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(void) {
    char input[MAX_LINE];
    char **tokens;

    printf("Sherlock Shell > ");
    fgets(input, MAX_LINE, stdin);

    tokens = split(input);
    execute_command(tokens);

    free(tokens);
}

int main(void) {
    loop();

    return 0;
}