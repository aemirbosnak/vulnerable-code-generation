//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = MAX_COMMAND_LENGTH;
    int words = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[words] = token;
        words++;
        if (words == bufsize) {
            bufsize += MAX_COMMAND_LENGTH;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }
        token = strtok(NULL, DELIM);
    }
    tokens[words] = NULL;
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
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop(char *prompt) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        tokens = split_string(input);
        execute_command(tokens);
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    loop("> ");
    return 0;
}