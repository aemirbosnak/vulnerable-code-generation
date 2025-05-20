//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
pid_t fork();
int execute_command(char **args);
void print_prompt();

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    print_prompt();

    while(fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);
        pid_t child_pid = fork();

        if(child_pid == -1) {
            fprintf(stderr, "Error: Failed to fork.\n");
        } else if(child_pid > 0) {
            int status;
            waitpid(child_pid, &status, 0);
        } else {
            execute_command(args);
            exit(0);
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = malloc(sizeof(char *));

    char *token = strtok(string, DELIM);

    while(token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;

        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
}

pid_t fork() {
    return fork();
}

int execute_command(char **args) {
    pid_t child_pid;
    int status;

    if(args[0] == NULL) {
        return 1;
    }

    child_pid = fork();

    if(child_pid == -1) {
        fprintf(stderr, "Error: Failed to fork.\n");
        return 1;
    } else if(child_pid > 0) {
        waitpid(child_pid, &status, 0);
    } else {
        if(execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: Failed to execute command.\n");
            return 1;
        }
    }

    return 0;
}

void print_prompt() {
    printf("> ");
}