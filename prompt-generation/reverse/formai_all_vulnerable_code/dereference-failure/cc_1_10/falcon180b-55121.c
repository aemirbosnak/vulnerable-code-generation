//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *));
    int i = 0;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;
    return tokens;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }

    return pid;
}

int execute_command(char **tokens) {
    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Command Not Found");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input_buffer[BUFFER_SIZE];
    char **tokens;

    while (1) {
        printf("> ");
        fgets(input_buffer, BUFFER_SIZE, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        tokens = split_string(input_buffer);
        execute_command(tokens);
    }

    return 0;
}