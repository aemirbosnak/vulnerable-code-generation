//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
int execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    int status;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        arguments = split_string(input, DELIM);
        status = execute_command(arguments);

        if (status == 0) {
            print_prompt();
        }
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    char **tokens = malloc(sizeof(char *));
    int count = 0;
    char *token = strtok(string, delimiter);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }

    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "Error: Empty command.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: Fork failed.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

void print_prompt(void) {
    printf("> ");
}