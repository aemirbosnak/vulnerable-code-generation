//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0
#define ERROR -1

char **split_string(char *string);
pid_t fork();
int execute_command(char **args);
void print_prompt(char *prompt);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;
    int status;

    print_prompt("> ");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        switch (fork()) {
            case -1:
                fprintf(stderr, "Error forking process\n");
                exit(1);
            case 0:
                status = execute_command(args);
                exit(status);
            default:
                waitpid(0, &status, 0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(string, DELIM);

    while (token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        errno = 0;
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

void print_prompt(char *prompt) {
    printf("%s", prompt);
}