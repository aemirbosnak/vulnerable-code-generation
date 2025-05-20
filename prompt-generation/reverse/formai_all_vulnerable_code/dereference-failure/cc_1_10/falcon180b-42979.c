//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
    char **tokens = NULL;
    int num_tokens = 0;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        num_tokens++;
        tokens = realloc(tokens, sizeof(char *) * num_tokens);
        tokens[num_tokens - 1] = token;
        token = strtok(NULL, DELIM);
    }

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return;
    }

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return;
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop(FILE *input) {
    char line[MAX_LINE_LENGTH];
    char **tokens;

    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        tokens = split_line(line);
        execute_command(tokens);
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    FILE *input;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    loop(input);

    fclose(input);
    return 0;
}