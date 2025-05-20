//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define TRUE 1
#define FALSE 0
#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    while (TRUE) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        arguments = split_string(input);
        execute_command(arguments);
    }
    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(string, DELIM);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        if (count >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;
    if (arguments[0] == NULL) {
        return 1;
    }
    if (strcmp(arguments[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 1;
}