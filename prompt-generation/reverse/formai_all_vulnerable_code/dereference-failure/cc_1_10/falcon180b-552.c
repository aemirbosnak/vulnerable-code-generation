//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
pid_t fork(void);
int execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t pid;

    print_prompt();

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        arguments = split_string(input, DELIM);

        if (arguments[0] == NULL) {
            continue;
        }

        pid = fork();

        if (pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (pid < 0) {
            printf("Error forking process\n");
        }

        waitpid(pid, NULL, 0);
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    char **tokens;
    int count = 0;
    char *token;

    tokens = malloc(sizeof(char *) * MAX_ARGUMENTS);

    if (tokens == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    token = strtok(string, delimiter);

    while (token!= NULL) {
        tokens[count] = token;
        count++;

        if (count >= MAX_ARGUMENTS) {
            printf("Too many arguments\n");
            exit(1);
        }

        token = strtok(NULL, delimiter);
    }

    tokens[count] = NULL;

    return tokens;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error executing command\n");
            exit(1);
        }
    } else if (pid < 0) {
        printf("Error forking process\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return -1;
        }
    }
}

void print_prompt(void) {
    printf("> ");
}