//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);
    int count = 0;

    while (token!= NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        fprintf(stderr, "Error: Command not found.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop(void) {
    char input[BUFFER_SIZE];
    char **tokens;

    printf("> ");
    fgets(input, BUFFER_SIZE, stdin);

    tokens = split_string(input);
    execute_command(tokens);

    free(tokens);
}

int main(void) {
    loop();

    return 0;
}